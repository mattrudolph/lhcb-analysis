#include "bu2rhomunu_loop.h"
#include "RhoMuSelectModule.h"
#include "TDirectory.h"
#include "TH2.h"
#include <iostream>

namespace bs2st_bu2rhomunu {

  bu2rhomunu_loop::bu2rhomunu_loop(TTree * tree, TDirectory * parentdir, std::string name) : AnalysisBase::DecayTreeLoop(tree,name) {

    if(parentdir != 0) {
      m_outdir = parentdir->mkdir(m_name.c_str());
    }
    
    attachTree(m_tree);

  }

  int bu2rhomunu_loop::cacheCandidate() {
    m_v_bu.push_back( Bu );
    m_v_rho.push_back( Rho );
    m_v_pip.push_back( Pip );
    m_v_pim.push_back( Pim );
    m_v_mu.push_back( Mu );
    return 0;
  }

  int bu2rhomunu_loop::clearCache() {
    m_v_bu.clear();
    m_v_rho.clear();
    m_v_pip.clear();
    m_v_pim.clear();
    m_v_mu.clear();
    return 0;
  }

  
  int bu2rhomunu_loop::execute() {

    for(size_t i=0; i<m_v_bu.size(); ++i ) {

      //only run this for 1 bs2st bc of multiple attached kaons
      if (i==0) {
        m_rhomu_mod->fillHistograms( m_v_bu[i], m_v_rho[i], m_v_pip[i], m_v_pim[i], m_v_mu[i] );
      }
    }
    return 0;
  }

  
  int bu2rhomunu_loop::initialize() {
    
    if(m_outdir==0) {
      std::cerr << "bu2rhomunu_loop::initialize(): no outdir available" << std::endl;
      return 1;
    }

    m_rhomu_mod = new RhoMuSelectModule(m_outdir);
    m_modules.push_back(m_rhomu_mod);
        
    AnalysisBase::BaseLoop::initialize();
    
    return 0;
  }    

}
