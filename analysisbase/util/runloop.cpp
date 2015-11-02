
#include <iostream>
#include "ExampleLoop.h"

#include "TFile.h"

int main() {

  std::cout << "Hello world" << std::endl;

  TFile f("test.root","RECREATE");
  
  AnalysisBase::ExampleLoop l;
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
