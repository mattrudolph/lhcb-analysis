#!/usr/bin/env python

"""
Generate a basic class structure inheriting from BaseLoop for an input TTree

"""

import sys
import os
from ROOT import TFile,TTree

from genbasicloop import preamble     

basevars = ['P','PT','PE','PX','PY','PZ','M','ID','OWNPV_X','OWNPV_Y','OWNPV_Z','OWNPV_XERR','OWNPV_YERR','OWNPV_ZERR','OWNPV_CHI2','OWNPV_NDOF','OWNPV_COV_[3][3]',]
momvars = ['ENDVERTEX_X','ENDVERTEX_Y','ENDVERTEX_Z','ENDVERTEX_XERR','ENDVERTEX_YERR','ENDVERTEX_ZERR','ENDVERTEX_CHI2','ENDVERTEX_NDOF','ENDVERTEX_COV_[3][3]',]
kidvars = ['ORIVX_X','ORIVX_Y','ORIVX_Z','ORIVX_XERR','ORIVX_YERR','ORIVX_ZERR','ORIVX_CHI2','ORIVX_NDOF','ORIVX_COV_[3][3]',]

def partclass(part, varlist):
    #check if mom or kid
    isMom = False
    isKid = False

    code = '    public:\n'
    for (t,var) in varlist:
        if var in basevars:
            continue
        if var in momvars:
            isMom = True
            continue
        if var in kidvars:
            isKid = True
            continue
        code += '      {:<20}  {:<};\n'.format(t,var)
    code+='    };\n\n'

    code0='    class {} :'.format(part)
    if not isMom and not isKid:
        code0 += ' public AnalysisBase::Particle'
    elif isMom and isKid:
        code0 += ' public AnalysisBase::InterParticle'
    elif isMom:
        code0+= ' public AnalysisBase::MotherParticle'
    elif isKid:
        code0 += ' public AnalysisBase::StableParticle'

    code0+=' {\n'

    return code0+code

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
    
    code='#include "Particles.h"\n'
    code += preamble(packname,args.classname)
    

    #make structures for the particles

    leaves = tree.GetListOfLeaves()
    import collections
    pldict = collections.OrderedDict()
    
    loners = []

    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        #these are already in the base decaytreeloop:
        if( n=='eventNumber' or n=='runNumber'):
            continue

        t = lf.GetTypeName()

        #some exceptions that need array - can be more dynamic in the future
        if "COV_" in n:
            n += "[3][3]"
        if n[:2] == 'PV':
            n+= "[100]"

        s = n.split('_',1)

        if(len(s) == 1 ):
            loners += [(t,n)]
        else:
            part = s[0]
            var = s[1]

            if part in pldict:
                pldict[ part ] += [(t,var)]
            else:
                pldict[ part ] = [ (t,var), ]


    code += '  namespace {} {{\n\n'.format(args.classname)
    for part,varlist in pldict.iteritems():
        code+=partclass(part,varlist)
    code +=  '  }\n\n'

    code += '  class {}_vars {{\n\n    public:\n'.format(args.classname)
    for t,n in loners:
        code += '    {:<20}  {:<};\n'.format(t,n)
    code += '\n'
    for part in pldict:
        code += '    {}::{:<6} {:<};\n'.format(args.classname,part,part)

    code += '\n    void attachTree(TTree * tree);\n\n  };\n}'

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
