
#include <iostream>
#include "bs2st2buk_kmux_loop.h"

#include "TFile.h"
#include "TTree.h"
#include "TApplication.h"

int main(int argc, char * argv[]) {

  //this is a workaround since it seems to avoid a crash where TBranch::fDirectory ends up invalid -- maybe has something to do with root linking?  the forced -b avoids another crash in ~TApplication with the graphics
  int tmpargc=2;
  char * tmpargv[] = {"runloop","-b"};
  TApplication theApp("App", &tmpargc, tmpargv);
  //


  std::cout << "Hello world" << std::endl;

  TFile f("/home/mrudolph/lhcb-analysis/bs2st_bu2kmutau/run/input/bs2st2buk_kmux_mc.root");
  TTree * tree = (TTree*) f.Get("Bs2st2BuK_KMuX_Tuple/DecayTree");
  std::cout << "Check tree get directory " << tree->GetDirectory() << ", branch = " << tree->GetBranch("Bs2st_ENDVERTEX_X")->GetDirectory() << ", file = " <<tree->GetBranch("Bs2st_ENDVERTEX_X")->GetDirectory()->GetFile() << std::endl;
  bs2st_bu2kmutau::bs2st2buk_kmux_loop l(tree);
  int res = l.initialize();
  if(res) 
    return res;

  res = l.loop();
  if(res) 
    return res;

  res = l.finalize();
  if(res) 
    return res;


  return 0;

}
