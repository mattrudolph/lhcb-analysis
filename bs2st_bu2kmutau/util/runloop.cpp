
#include <iostream>
#include "bs2st2buk_kmux_loop.h"

#include "TFile.h"
#include "TTree.h"
#include "TApplication.h"

int main(int argc, char * argv[]) {
  TApplication theApp("App", &argc, argv);
  std::cout << "Hello world" << std::endl;

  TFile f("input/bs2st2buk_kmux_mc.root");
  TTree * tree = (TTree*) f.Get("Bs2st2BuK_KMuX_Tuple/DecayTree");
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
