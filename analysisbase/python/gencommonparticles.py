#!/usr/bin/env python

"""
Generate a basic set of particle classes for a package based on a tree

"""

import sys
import os
from ROOT import TFile,TTree

from basevars import *

def partclass( part, typedvarlist ):
    parttype = typedvarlist[0]
    varlist = typedvarlist[1]
    code = '  class {} : public AnalysisBase::{} {{\n'.format( part, parttype )
    code += '  public:\n'
    for(t,var) in varlist:
        code += '    {:<20}  {:<};\n'.format(t,var)
    code +='  };\n\n'
    return code


def gencommonparticles( tree, outdir ):
    #create a class with leaves as data members
    packname = os.path.basename(outdir)

    defname = packname.upper().replace('_','')
    
    code ='#ifndef {}_PARTICLES_H\n#define {}_PARTICLES_H\n\n#include "Particles.h"\n\n'.format(defname,defname)
    code +='namespace {} {{\n\n'.format(packname)

    #make structures for the particles

    leaves = tree.GetListOfLeaves()
    import collections
    pldict = collections.OrderedDict()
    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        t = lf.GetTypeName()
        
        #some exceptions that need array - can be more dynamic in the future
        if "COV_" in n:
            n += "[3][3]"
        if n[:2] == 'PV':
            n+= "[100]"

        s = n.split('_',1)

        if len(s) > 1 and n not in eventvars:
            part = s[0]
            var = s[1]

            if part not in pldict:
                #default to basic particle
                pldict[ part ] = ("Particle", [])

            #never need to update base variables
            if var in basevars:
                continue
                
            #check if type should update if its in a list
            #if not in a base list then add it to this particle but can't say anything new about type
            if var in momvars:
                if pldict[part][0] == "StableParticle":
                    pldict[part] = ("InterParticle",pldict[part][1])
                elif pldict[part][0] == "Particle":
                    pldict[part] = ("MotherParticle",pldict[part][1])
            elif var in kidvars:
                if pldict[part][0] == "MotherParticle":
                    pldict[part] = ("InterParticle",pldict[part][1])
                elif pldict[part][0]=="Particle":
                    pldict[part] = ("StableParticle",pldict[part][1])
            else:
                pldict[part] = (pldict[part][0], pldict[part][1] + [(t,var),] )


    for part,typedvarlist in pldict.iteritems():
        code +=partclass(part,typedvarlist)
    code +=  '}\n\n#endif\n'

    with open(outdir+'/include/' + packname.capitalize() + 'Particles.h','w') as ftarget:
        ftarget.write(code)

    #also write out the python version
    with open(outdir+'/python/'+ packname + 'particles.py','w') as ftarget:
        ftarget.write( "from collections import OrderedDict\npldict = " + repr(pldict))

    #return the dictionary of what we created
    return pldict
    

if __name__ == '__main__':
    import argparse
    
    parser = argparse.ArgumentParser(
        description = "Generate basic tree looping structure")
    parser.add_argument('-i','--input',type=str,required=True,
                        help="Input file with tree")
    parser.add_argument('-t','--tree',type=str,required=True,
                        help="Path in file to tree")
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


    outdir = os.path.realpath(args.output)

    gencommonparticles( tree, outdir )
