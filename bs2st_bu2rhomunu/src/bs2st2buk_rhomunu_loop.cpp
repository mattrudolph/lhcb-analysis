
#include "bs2st2buk_rhomunu_loop.h"
//#include "MissingMass.h"
#include "MissingMassModule.h"
#include "TDirectory.h"
#include "TH2.h"
#include <iostream>

namespace bs2st_bu2rhomunu {

  bs2st2buk_rhomunu_loop::bs2st2buk_rhomunu_loop(TTree * tree, TDirectory * parentdir, std::string name) : AnalysisBase::DecayTreeLoop(tree,name) {

    if(parentdir != 0) {
      m_outdir = parentdir->mkdir(m_name.c_str());
    }
    
    attachTree(m_tree);

  }

  int bs2st2buk_rhomunu_loop::cacheCandidate() {
    m_v_bs2st.push_back( Bs2st );
    m_v_bu.push_back( Bu );
    m_v_rho.push_back( Rho );
    m_v_pip.push_back( Pip );
    m_v_pim.push_back( Pim );
    m_v_mu.push_back( Mu );
    m_v_km.push_back( Km );
    return 0;
  }

  int bs2st2buk_rhomunu_loop::clearCache() {
    m_v_bs2st.clear();
    m_v_bu.clear();
    m_v_rho.clear();
    m_v_pip.clear();
    m_v_pim.clear();
    m_v_mu.clear();
    m_v_km.clear();
    return 0;
  }

  int bs2st2buk_rhomunu_loop::execute() {

    for(size_t i=0; i<m_v_bs2st.size(); ++i ) {
    
      std::vector<double> vmm = m_mm_mod->process( m_v_bu[i], m_v_km[i], m_v_mu[i], m_v_rho[i] );

      double vis_e = (m_v_mu[i].PE + m_v_rho[i].PE)/1000.;
      for(size_t j=0; 2*j+1 < vmm.size(); ++j) {

        double m_e = vmm[2*j];

        std::vector<double> halfv;
        halfv.push_back( m_e );
        halfv.push_back( vmm[2*j+1] );

        if( m_e > 0 ) {
          m_mm_mod_cut->fillHistograms( halfv, vis_e);
        }
        
        // for(std::vector<double>::iterator it=vmm.begin(); it < vmm.end(); ) {
        //   if( *it < 8 ) {
        //     //erase the next two
        //     it = vmm.erase(it);
        //     it = vmm.erase(it);
        //   } else {
        //     //or skip to the next pair
        //     it +=2;
        //   }
        // }

        // m_mm_cutmod->fillHistograms( vmm, vis_e );
      }
    }
    return 0;
  }

  int bs2st2buk_rhomunu_loop::initialize() {
    
    if(m_outdir==0) {
      std::cerr << "bs2st2buk_rhomunu_loop::initialize(): no outdir available" << std::endl;
      return 1;
    }
    
    m_mm_mod = new bs2st_bu2kmutau::MissingMassModule(m_outdir,"MissingMass_Raw");
    m_modules.push_back(m_mm_mod);

    m_mm_mod_cut = new bs2st_bu2kmutau::MissingMassModule(m_outdir,"MissingMass_Physical");
    m_modules.push_back(m_mm_mod_cut);
    
    AnalysisBase::BaseLoop::initialize();
    
    return 0;
  }    

}
