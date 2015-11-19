

#include "BaseLoop.h"
#include "AnalysisModule.h"
#include "TDirectory.h"
#include "TTree.h"
#include <iostream>

namespace AnalysisBase {

  BaseLoop::BaseLoop(TTree * tree, std::string name) : m_tree(tree), m_name(name), m_outdir(0) {

  }

  int BaseLoop::initialize() {

    ///Do any setup you want before the actual looping like setting up histograms
    ///BaseLoop will handle booking for any AnalysisModules you add to its vector

    for( std::vector<AnalysisModule*>::const_iterator it=m_modules.begin(); it!=m_modules.end(); ++it )
      (*it)->bookHistograms();
    
    return 0;
  }

  int BaseLoop::finalize() {
    ///Any final steps after loop like writing output
    ///BaseLoop will write out everything in its object vector to the outdir if either are specified

    if(m_outdir) {
      m_outdir->cd();
      for( size_t i =0; i< m_v_out.size(); ++i) {
        m_v_out[i]->Write();
      }
    }

    //Handle the output for all the attached modules
    for( std::vector<AnalysisModule*>::const_iterator it=m_modules.begin(); it!=m_modules.end(); ++it ) {
      (*it)->writeHistograms();
    }
    
    return 0;
  }

  int BaseLoop::loop() {

    ///Basic loop over a tree, calling execute on each entry

    if( m_tree == 0 ) {
      std::cout << "WARNING BaseLoop::execute(): attempt to loop without a tree, doing nothing" << std::endl;
      return 0;
    }

    Long64_t nentries = m_tree->GetEntriesFast();
    std::cout << "Begin loop over " << nentries << " entries" << std::endl;
   
    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = m_tree->LoadTree(jentry);
      if (ientry < 0) { 
        std::cerr << "ERROR BaseLoop::execute(): LoadTree returns " << ientry << " for entry " << jentry << std::endl;
        return 1;
      }

      nb = m_tree->GetEntry(jentry);   nbytes += nb;

      int res = execute();

      if(res!=0) {
        std::cout << "WARNING BaseLoop::execute(): entry " << jentry << " returns error from execute." << std::endl;
      }
    }

    std::cout << "Read in " << nbytes << " bytes" << std::endl;

    return 0;
  }

  

}
