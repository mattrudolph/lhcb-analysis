

#include "bs2st2buk_jpsik_loop.h"
#include "MissingMassModule.h"
#include "Bs2stSelectModule.h"
#include "TFile.h"
#include "TH2.h"
#include <iostream>

namespace bs2st_bu2kmutau {

  bs2st2buk_jpsik_loop::bs2st2buk_jpsik_loop(TTree * tree, TDirectory * parentdir, std::string name) : AnalysisBase::DecayTreeLoop(tree,name) {

    if(parentdir != 0) {
      m_outdir = parentdir->mkdir(m_name.c_str());
    }
    
    attachTree(m_tree);

  }

  int bs2st2buk_jpsik_loop::cacheCandidate() {
    m_v_bs2st.push_back( Bs2st );
    m_v_bu.push_back( Bu );
    m_v_km.push_back( Km );
    m_v_jpsi.push_back( Jpsi );
    m_v_mup.push_back( Mup);
    m_v_mum.push_back( Mum );
    m_v_kp.push_back( Kp );

    return 0;
  }

  int bs2st2buk_jpsik_loop::clearCache() {
    m_v_bs2st.clear();
    m_v_bu.clear();
    m_v_jpsi.clear();
    m_v_mup.clear();
    m_v_mum.clear();
    m_v_kp.clear();
    m_v_km.clear();
    return 0;
  }

  int bs2st2buk_jpsik_loop::execute() {

    for(size_t i=0; i<m_v_bs2st.size(); ++i ) {

      m_h_bs2st_m->Fill( m_v_bs2st[i].M/1000. );

      //Check if in signal region
      bool inSig = (fabs(m_v_bs2st[i].M - 5839.83) < 25 );


      std::vector<double> vmm = m_mm_mod->process( m_v_bu[i], m_v_km[i], m_v_mup[i], m_v_kp[i] );
      double vis_e = (m_v_mup[i].PE + m_v_kp[i].PE)/1000.;
      for(size_t i=0; 2*i+1 < vmm.size(); ++i) {
     
        double b_e = vmm[2*i] + vis_e;

        if( inSig ) {
          m_sel_sig->fillHistograms( m_v_km[i], m_v_bu[i], b_e );
        } else {
          m_sel_bkg->fillHistograms( m_v_km[i], m_v_bu[i], b_e );
        }

      }
      
      // vmm = m_mm_mod->process( m_v_bu[i], m_v_km[i], m_v_mum[i], m_v_kp[i] );
      // vis_e = (m_v_mum[i].PE + m_v_kp[i].PE)/1000.;
    }
    return 0;
  }

  int bs2st2buk_jpsik_loop::initialize() {

    if(m_outdir==0) {
      std::cerr << "bs2st2buk_jpsik_loop::initialize(): no outdir available" << std::endl;
      return 1;
    }

    m_mm_mod = new MissingMassModule(m_outdir);
    m_modules.push_back(m_mm_mod);

    m_sel_sig = new Bs2stSelectModule(m_outdir,"Bs2stSelect_Sig");
    m_modules.push_back(m_sel_sig);
    
    m_sel_bkg = new Bs2stSelectModule(m_outdir,"Bs2stSelect_Bkg");
    m_modules.push_back(m_sel_bkg);
    
    m_h_bs2st_m = new TH1F("h_bs2st_m","mass of reco bs2st; M [GeV]",200,5,7.5);
    m_v_out.push_back(m_h_bs2st_m);

    AnalysisBase::BaseLoop::initialize();
    
    return 0;
  }    

}
