#ifndef BASELOOP_H
#define BASELOOP_H

/**
   Basic Class for looping on a TTree
 */

class TTree;
class TDirectory;
class TObject;

#include <vector>
#include <string>

namespace AnalysisBase{

  class AnalysisModule;
  
  class BaseLoop {
    
  public:
    BaseLoop(TTree* tree = 0, std::string name = "BaseLoop");

    virtual ~BaseLoop() {}
    
    virtual int initialize();
  
    virtual int loop();

    virtual int finalize();
    
  protected:

    //This is what I loop over
    TTree * m_tree;

    //This is my name (commonly used to define output names, etc)
    std::string m_name;
    
    //File for output
    TDirectory * m_outdir;

    //This keeps track of things I want to write out that aren't attached to a module
    std::vector<TObject*> m_v_out;

    std::vector<AnalysisModule*> m_modules;
    
    virtual int execute() = 0;

  };

}

#endif
