#ifndef BASELOOP_H
#define BASELOOP_H

/**
   Basic Class for looping on a TTree
 */

class TTree;
class TFile;
class TObject;

#include <vector>

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

    //File for output
    TFile * m_outfile;

    //This keeps track of things I want to write out
    std::vector<TObject*> m_v_out;

    virtual int execute() = 0;

  };

}

#endif
