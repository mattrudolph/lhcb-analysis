#!/usr/bin/env python

"""
Generate a basic class structure inheriting from BaseLoop for an input TTree

"""

import sys
import os
from ROOT import TFile,TTree



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

    #create a class with leaves as data members
    outdir = os.path.realpath(args.output)
    packname = os.path.basename(outdir)
    
    code='#ifndef ROOT_Rtypes\n#include "Rtypes.h"\n#endif\n\n'
    code += 'class TTree;\n\nnamespace {} {{\n\n'.format(packname)
    filename = os.path.basename(tfile.GetName())[:-5]
    code += '  class {}Vars {{\n\n    public:\n\n'.format(filename)
    
    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        t = lf.GetTypeName()

        code += '      {:<20}  {:<};\n'.format(t,n)

    code += '\n      void attachTree(TTree * tree);\n\n  };\n}'

    print code

    with open(outdir+'/include/{}Vars.h'.format(filename),'w') as ftarget:
        ftarget.write(code)

    #create cpp file that attaches those members to a tree
    code = '#include "{}Vars.h"\n'.format(filename)
    code += '#include "TTree.h"\n\n'
    code += 'namespace {} {{\n\n'.format(packname)
    code += '  void {}Vars::attachTree(TTree * tree) {{\n\n'.format(filename)

    for lf in tree.GetListOfLeaves():
        n = lf.GetName()
        t = lf.GetTypeName()

        code += '    tree->SetBranchAddress("{}",&{});\n'.format(n,n)

    code += '\n  }\n\n}\n'

    print code 
    with open(outdir+'/src/{}Vars.cpp'.format(filename),'w') as ftarget:
        ftarget.write(code)
