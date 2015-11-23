
#include <iostream>
#include "bs2st2buk_rhomunu_loop.h"

#include "TFile.h"
#include "TTree.h"

int main(int argc, char * argv[]) {

  //this is a workaround since it seems to avoid a crash where TBranch::fDirectory ends up invalid -- maybe has something to do with root linking?  the forced -b avoids another crash in ~TApplication with the graphics
  // int tmpargc=2;
  // char * tmpargv[] = {"runloop","-b"};
  // TApplication theApp("App", &tmpargc, tmpargv);
  //


  TFile f("/Users/msrudolp/lhcb-analysis/bs2st_bu2rhomunu/run/input/bs2st2buk_rhomunu_2011up.root");
  TTree * tree = (TTree*) f.Get("Bs2st2BuK_RhoMuX_Tuple/DecayTree");

  TFile fout("test.root","RECREATE");
  
  
  bs2st_bu2rhomunu::bs2st2buk_rhomunu_loop l(tree,&fout,"Signal");
  int res = l.initialize();
  if(res) 
    return res;

  res = l.loop();
  if(res) 
    return res;

  res = l.finalize();
  if(res) 
    return res;

  // TTree * treeSS = (TTree*) f.Get("Bs2st2BuKSS_KMuX_Tuple/DecayTree");

  // bs2st_bu2kmutau::bs2st2buk_kmux_loop lSS(treeSS,&fout,"SameSignBG");
  // res = lSS.initialize();
  // if(res) 
  //   return res;

  // res = lSS.loop();
  // if(res) 
  //   return res;

  // res = lSS.finalize();
  // if(res) 
  //   return res;
  

  return 0;

}
