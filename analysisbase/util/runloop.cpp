
#include <iostream>
#include "BaseLoop.h"

#include "TFile.h"

int main() {

  std::cout << "Hello world" << std::endl;

  TFile f("test.root","RECREATE");
  
  AnalysisBase::BaseLoop b;
  b.printIdx();
  
  return 0;

}
