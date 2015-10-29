#ifndef BASELOOP_H
#define BASELOOP_H

/**
   Basic Class for looping on a TTree
 */

#include "TChain.h"

namespace AnalysisBase{

  class BaseLoop {
    
  public:
    BaseLoop(TChain* chain = 0);

    virtual ~BaseLoop() {}
    
    void printIdx();
  
  private:

    //This is what I loop over
    TChain * m_chain;

    int m_idx;

  };

}

#endif
