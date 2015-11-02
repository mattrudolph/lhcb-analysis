#ifndef BASELOOP_H
#define BASELOOP_H

/**
   Basic Class for looping on a TTree
 */

#include "TTree.h"

namespace AnalysisBase{

  class BaseLoop {
    
  public:
    BaseLoop(TTree* tree = 0);

    virtual ~BaseLoop() {}
    
    virtual int initialize();
  
    virtual int loop();

    virtual int finalize();
    
  protected:

    //This is what I loop over
    TTree * m_tree;

    virtual int execute() = 0;

  };

}

#endif
