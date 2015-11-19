

#include "bs2st2buk_kmux_loop.h"
#include "MissingMass.h"
#include "MissingMassModule.h"
#include "TDirectory.h"
#include "TH2.h"
#include <iostream>

namespace bs2st_bu2kmutau {

  bs2st2buk_kmux_loop::bs2st2buk_kmux_loop(TTree * tree, TDirectory * parentdir, std::string name) : AnalysisBase::DecayTreeLoop(tree,name) {

    if(parentdir != 0) {
      m_outdir = parentdir->mkdir(m_name.c_str());
    }
    
    attachTree(m_tree);

  }

  int bs2st2buk_kmux_loop::cacheCandidate() {
    m_v_bs2st.push_back( Bs2st );
    m_v_bu.push_back( Bu );
    m_v_mu.push_back( Mu );
    m_v_kp.push_back( Kp );
    m_v_km.push_back( Km );
    return 0;
  }

  int bs2st2buk_kmux_loop::clearCache() {
    m_v_bs2st.clear();
    m_v_bu.clear();
    m_v_mu.clear();
    m_v_kp.clear();
    m_v_km.clear();
    return 0;
  }

  int bs2st2buk_kmux_loop::execute() {

    for(size_t i=0; i<m_v_bs2st.size(); ++i ) {
    
      std::vector<double> vmm = m_mm_mod->process( m_v_bu[i], m_v_km[i], m_v_mu[i], m_v_kp[i] );

      double vis_e = (m_v_mu[i].PE + m_v_kp[i].PE)/1000.;
      
      for(size_t i=0; 2*i+1 < vmm.size(); ++i) {
        //check for good amount of missing energy
        if( vmm[2*i] > 8 )
          m_mm_cutmod->fillHistograms( vmm[2*i+1], vmm[2*i], vis_e );
      }
      
    }
    return 0;
  }

  int bs2st2buk_kmux_loop::initialize() {
    
    if(m_outdir==0) {
      std::cerr << "bs2st2buk_kmux_loop::initialize(): no outdir available" << std::endl;
      return 1;
    }
    
    m_mm_mod = new MissingMassModule(m_outdir,"MissingMass_Raw");
    m_modules.push_back(m_mm_mod);

    m_mm_cutmod = new MissingMassModule(m_outdir,"MissingMass_Cut");
    m_modules.push_back(m_mm_cutmod);
    
    AnalysisBase::BaseLoop::initialize();
    
    return 0;
  }    

}
