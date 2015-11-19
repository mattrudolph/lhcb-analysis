

#include "DecayTreeLoop.h"
#include "TTree.h"
#include <iostream>
#include "TDirectory.h"

namespace AnalysisBase {

  DecayTreeLoop::DecayTreeLoop(TTree * tree, std::string name) : BaseLoop(tree, name) {

    TBranch * bRunNumber = m_tree->GetBranch("runNumber");
    TBranch * bEventNumber = m_tree->GetBranch("eventNumber");

    if(bRunNumber == 0 || bEventNumber==0) {
      std::cout << "INFO DecayTreeLoop: no run or event number in tree; will not cache candidates" << std::endl;
      m_doCache = false;
    } else {
      m_doCache = true;
    }

    bRunNumber->SetAddress( &runNumber);
    bEventNumber->SetAddress( &eventNumber);

  }

  int DecayTreeLoop::initialize() {

    ///Do any setup you want before the actual looping like setting up histograms
    ///DecayTreeLoop just makes an empty version if you have nothing to declare
    
    return 0;
  }

  int DecayTreeLoop::loop() {

    ///Basic loop over a tree, calling execute on each entry

    if( m_tree == 0 ) {
      std::cout << "WARNING DecayTreeLoop::execute(): attempt to loop without a tree, doing nothing" << std::endl;
      return 0;
    }

    Long64_t nentries = m_tree->GetEntriesFast();
    Long64_t nevents = 0;
    std::cout << "Begin loop over " << nentries << " entries" << std::endl;
   
    Long64_t nbytes = 0, nb = 0;
    Long64_t ientry = m_tree->LoadTree(0);
    if (ientry < 0) { 
      std::cerr << "ERROR DecayTreeLoop::execute(): LoadTree returns " << ientry << " for entry " << 0 << std::endl;
      return 1;
    }
    nb = m_tree->GetEntry(0);   nbytes += nb;
    for (Long64_t jentry=0; jentry<nentries;) {
      if(m_doCache)
        clearCache();

      //read ahead in run+event number to identify all candidates in same event
      UInt_t currRun = runNumber;
      ULong64_t currEv = eventNumber;
      do {
        // save a candidate -- implemented in the daughter class
        cacheCandidate();

        //do the looping here
        jentry++;
        if(jentry == nentries)
          break;
        Long64_t ientry = m_tree->LoadTree(jentry);
        if (ientry < 0) { 
          std::cerr << "ERROR DecayTreeLoop::execute(): LoadTree returns " << ientry << " for entry " << jentry << std::endl;
          return 1;
        }
        nb = m_tree->GetEntry(jentry);   nbytes += nb;
          
      } while( m_doCache && currEv == eventNumber && currRun == runNumber );
      //the last entry I read is a different event and will be used next overall loop
      //this happens even with only 1 candidate per event --> don't iterate jentry in the for loop

      nevents++;
      //now execute with all candidates of one event in the cache
      int res = execute();

      if(res!=0) {
        std::cout << "WARNING DecayTreeLoop::execute(): entry " << jentry << " returns error from execute." << std::endl;
      }
    }

    std::cout << "Read in " << nbytes << " bytes" << std::endl;
    std::cout << "Processed " << nentries << " candidates in " << nevents << " events" << std::endl;

    return 0;
  }

  

}
