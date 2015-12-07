#!/usr/bin/env python

"""
Generate a basic class structure inheriting from BaseLoop for an input TTree

"""

import sys
import os
from ROOT import TFile,TTree

from genbasicloop import preamble     

def preamble(packname,classname):
    code = '#ifndef ROOT_Rtypes\n#include "Rtypes.h"\n#endif\n\nclass TTree;\n\n'
    code +='namespace {} {{\n\n'.format(packname)
    return code


from basevars import *


def partaddresses(part,varlist):
    code = ''
    for (t,var) in varlist:
        if '[' in var: #array variable
            n = var[:var.find('[')]
            code+='    tree->SetBranchAddress("{}_{}",{}.{});\n'.format(part,n,part,n)
        else:
            code+= '    tree->SetBranchAddress("{}_{}",&{}.{});\n'.format(part,var,part,var)
    return code

if __name__ == '__main__':
    import argparse
    
    parser = argparse.ArgumentParser(
        description = "Generate basic tree looping structure")
    parser.add_argument('-i','--input',type=str,required=True,
                        help="Input file with tree")
    parser.add_argument('-t','--tree',type=str,required=True,
                        help="Path in file to tree")
    parser.add_argument('-c','--classname',type=str,required=True,
                        help="Class name to use for vars class")
    parser.add_argument('-o','--output',type=str,required=True,
                        help="Path to output package area")
    args = parser.parse_args()
    
    if not os.path.isdir( args.output ):
        print "Output path is not a directory"
        sys.exit()

    tfile = TFile(args.input)
    tree = tfile.Get(args.tree)

    if tree is None:
        print "Did not find specified tree"
        sys.exit()

    #create a class with leaves as data members
    outdir = os.path.realpath(args.output)
    packname = os.path.basename(outdir)
    defname = packname.upper().replace('_','')
    #create the derived particles for this package and get their dictionary back
    import gencommonparticles
    packparts = gencommonparticles.gencommonparticles( tree, outdir )

    code='#ifndef {}_VARS_H\n#define {}_VARS_H\n\n'.format(defname,defname)
    
    code+='#include "{}Particles.h"\n'.format(packname.capitalize())
    code+='class TTree;\n\nnamespace {} {{\n\n'.format(packname)
    

    #make structures for the particles

    leaves = tree.GetListOfLeaves()
    import collections

    #dictionary to keep track of ALL the variables we have available -- need all so we can set branch addresses
    pldict = collections.OrderedDict()
    
    loners = []

    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        t = lf.GetTypeName()

        if n == 'eventNumber' or n=='runNumber':
            continue
        
        #some exceptions that need array - can be more dynamic in the future
        if "COV_" in n:
            n += "[3][3]"
        if n[:2] == 'PV':
            n+= "[100]"

        s = n.split('_',1)

        if(len(s) == 1): #new event level variable
            loners += [(t,n)]
        else: #some particle
            part = s[0]
            var = s[1]

            #first add it to the pldict
            if part not in pldict:
                pldict[ part ] = [ (t,var), ]
            else:
                pldict[ part ] += [ (t,var) ]

    #now we need to figure out the derivation for each particle

    #this dictionary tells you what the type will be in the _vars class member
    classdict = {}
    #this keeps track of which variables are new and need members declared
    extravarsdict = {}
    #list of particles we need to create a new derived class for, with what type they should inherit from
    derivedtypedict = {}

    #Loop over all the particles we want to bind:
    for part,varlist in pldict.iteritems():
        if part in packparts: #we have this type of particle in the package particles
            #determine if we have any extra variables
            extravarsdict[part] = []
            for var in varlist:
                if var not in packparts[part][1] and var[1] not in basevars:
                    #check if its in the intermediate class definition
                    if (packparts[part][0] == 'MotherParticle' and var[1] not in momvars) or (packparts[part][0] == 'InterParticle' and var[1] not in intervars) or (packparts[part][0] == 'StableParticle' and var[1] not in kidvars):
                        extravarsdict[part] += [var]

            if len(extravarsdict[part]) == 0:
                #can just create an instance of the package type
                classdict[part] = '{}::{}'.format(packname,part)
            else:
                #have to create a new one in the new namespace we need
                classdict[part] = '{}::{}'.format(args.classname,part)
                derivedtypedict[part] = '{}::{}'.format(packname,part)
                
        else: #not created yet -- need to make a new one deriving from a base particle type
            classdict[part] = '{}::{}'.format(args.classname,part)
            derivedtypedict[part] = 'AnalysisBase::Particle'
            extravarsdict[part] = []
            for var in varlist:
                if var[1] in basevars:
                    continue
                if var[1] in momvars:
                    if derivedtypedict[part] == 'AnalysisBase::StableParticle':
                        derivedtypedict[part] = 'AnalysisBase::InterParticle'
                    elif derivedtypedict[part] == 'AnalysisBase::Particle':
                        derivedtypedict[part] = 'AnalysisBase::MotherParticle'
                elif var[1] in kidvars:
                    if derivedtypedict[part] == 'AnalysisBase::MotherParticle':
                        derivedtypedict[part] = 'AnalysisBase::InterParticle'
                    elif derivedtypedict[part] == 'AnalysisBase::Particle':
                        derivedtypedict[part] = 'AnalysisBase::StableParticle'
                else: #this variable is new
                    extravarsdict[part] += [var]


    #derived namespace
    code += '  namespace {} {{\n\n'.format(args.classname)
    ##Now do we need new classes in the derived namespace?
    for part in pldict:
        if len(extravarsdict[part]) > 0:
            #need one for this particle
            code += '    class {} : public {} {{\n    public:\n'.format(part, derivedtypedict[part])
            for var in extravarsdict[part]:
                code+='      {:<20}  {:<};\n'.format(var[0],var[1])
            code += '    };\n\n'

    #end the derived namespace
    code += '  }\n\n'
        
    #now make the variabels class
    code += '  class {}_vars : public AnalysisBase::EventInfo {{\n\n    public:\n'.format(args.classname)
    #now the particle members
    for part in pldict:
        code += '    {:<30}  {:<};\n'.format( classdict[part], part)
    code += '\n'
    #now the extra loner variables
    for (t,var) in loners:
        if var not in eventvars:
            code += '    {:<30}  {:<};\n'.format(t,var)
        
    code += '\n    void attachTree(TTree * tree);\n\n  };\n}\n\n#endif\n'

    print code

    with open(outdir+'/include/{}_vars.h'.format(args.classname),'w') as ftarget:
        ftarget.write(code)

    
    #create cpp file that attaches those members to a tree
    code = '#include "{}_vars.h"\n'.format(args.classname)
    code += '#include "TTree.h"\n\n'
    code += 'namespace {} {{\n\n'.format(packname)
    code += '  void {}_vars::attachTree(TTree * tree) {{\n\n'.format(args.classname)

    for part,varlist in pldict.iteritems():
        code+=partaddresses(part,varlist)
    code+='\n'
    for t,n in loners:
        if '[' in n:
            n = n[:n.find('[')]
            code+= '    tree->SetBranchAddress("{}",{});\n'.format(n,n)
        else:
            code+= '    tree->SetBranchAddress("{}",&{});\n'.format(n,n)

    code += '\n  }\n\n}\n'

    print code

    with open(outdir+'/src/{}_vars.cpp'.format(args.classname),'w') as ftarget:
        ftarget.write(code)
