#ifndef DECAYTREELOOP_H
#define DECAYTREELOOP_H

/**
   Basic Class for looping on a TTree
 */

#include "TTree.h"
#include "BaseLoop.h"

namespace AnalysisBase{

  class DecayTreeLoop : public BaseLoop {
    
  public:
    DecayTreeLoop(TTree* tree = 0);

    virtual ~DecayTreeLoop() {}
    
    virtual int initialize();
  
    virtual int loop();

    virtual int finalize();
    
  protected:

    //Need event and run number
    UInt_t  runNumber;
    ULong64_t   eventNumber;

    TBranch*   m_bRunNumber;
    TBranch*   m_bEventNumber;

    //If we are doing the cache over all candidites in an event
    bool m_doCache;

    virtual int cacheCandidate() = 0;
    virtual int clearCache() = 0;
    virtual int execute() = 0;

  };

}

#endif
