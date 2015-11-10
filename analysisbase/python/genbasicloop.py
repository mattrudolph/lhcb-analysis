#!/usr/bin/env python

"""
Generate a basic class structure inheriting from BaseLoop for an input TTree

"""

import sys
import os
from ROOT import TFile,TTree


def preamble(packname,classname):
    code = '#ifndef ROOT_Rtypes\n#include "Rtypes.h"\n#endif\n\nclass TTree;\n\n'
    code +='namespace {} {{\n\n'.format(packname)
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
    
    code=preamble(packname,args.classname)
    code +='  class {}_vars {{\n\n    public:\n\n'.format(args.classname)

    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        t = lf.GetTypeName()

        code += '      {:<20}  {:<};\n'.format(t,n)

    code += '\n      void attachTree(TTree * tree);\n\n  };\n}'

    print code

    with open(outdir+'/include/{}_vars.h'.format(args.classname),'w') as ftarget:
        ftarget.write(code)

    #create cpp file that attaches those members to a tree
    code = '#include "{}_vars.h"\n'.format(classname)
    code += '#include "TTree.h"\n\n'
    code += 'namespace {} {{\n\n'.format(packname)
    code += '  void {}_vars::attachTree(TTree * tree) {{\n\n'.format(classname)

    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        t = lf.GetTypeName()

        code += '    tree->SetBranchAddress("{}",&{});\n'.format(n,n)

    code += '\n  }\n\n}\n'

    print code 
    with open(outdir+'/src/{}_vars.cpp'.format(classname),'w') as ftarget:
        ftarget.write(code)
