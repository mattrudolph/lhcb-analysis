

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
      
      m_h_bs2st_m_raw->Fill( m_v_bs2st[i].M/1000. );
      
      //Check if in signal region
      bool inSig = (fabs(m_v_bs2st[i].M - 5839.83) < 25 );
      double meas_b_e = m_v_bu[i].PE/1000.;

      std::vector<double> vmm = m_mm_mod->process( m_v_bu[i], m_v_km[i], m_v_mup[i], m_v_kp[i] );
      double vis_e = (m_v_mup[i].PE + m_v_kp[i].PE)/1000.;

      if( vmm.size() == 4 ) {
        m_h_bs2st_m_2sol->Fill( m_v_bs2st[i].M/1000. );
      }

      if(!inSig) {
        m_mm_mod_bkg->fillHistograms( vmm, vis_e);
      }
      
      double de = 100000000.0;
      size_t idx = vmm.size();
      for(size_t j=0; 2*j+1 < vmm.size(); ++j) {

        double m_e = vmm[2*j];
        //require solution to be physical in energy
        // if( m_e < 0 ) {
        //   continue;
        // }
        
        double b_e = m_e + vis_e;

        m_h_bs2st_m->Fill( m_v_bs2st[i].M/1000. );
        m_h_bs2st_e->Fill( m_v_bs2st[i].PE/1000. );
        if(m_e > 0.){
          m_h_bs2st_m_cut->Fill( m_v_bs2st[i].M/1000. );
        }
        
        if( inSig ) {
          if ( fabs(b_e - meas_b_e) < de ) {
            de = fabs(b_e - meas_b_e);
            idx = j;
          }

          m_sel_sig->fillHistograms( m_v_km[i], m_v_bu[i], b_e , m_e );
        } else {
          m_sel_bkg->fillHistograms( m_v_km[i], m_v_bu[i], b_e, m_e );
        }
      }

      //Only process closest measurement for signal region events
      if( idx != vmm.size()) {
        for(size_t j=0; 2*j+1 < vmm.size(); ++j) {
          //require solution to be physical in energy
          double m_e = vmm[2*j];
          // if( m_e < 0 )
          //   continue;
          double b_e = m_e + vis_e;

          if(inSig) {
            if( j==idx ) {
              m_sel_sig_right->fillHistograms( m_v_km[i], m_v_bu[i], b_e, m_e );
              m_h_b_de_right->Fill( b_e - meas_b_e );
            } else {
              m_sel_sig_wrong->fillHistograms( m_v_km[i], m_v_bu[i], b_e, m_e );
              m_h_b_de_wrong->Fill( b_e - meas_b_e );
            }
          }
          std::vector<double> halfv;
          halfv.push_back( m_e );
          halfv.push_back( vmm[2*j+1] );
          if( j==idx ) {
            m_mm_mod_right->fillHistograms( halfv, vis_e);
          } else {
            m_mm_mod_wrong->fillHistograms( halfv, vis_e);
          }

          
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
    
    m_mm_mod_bkg = new MissingMassModule(m_outdir,"MissingMassSideband");
    m_modules.push_back(m_mm_mod_bkg);

    //unlike the other right/wrong selection modules -- these also require a positive missing energy sol'n, but not that we are in the signal region
    m_mm_mod_right = new MissingMassModule(m_outdir,"MissingMassRight");
    m_modules.push_back(m_mm_mod_right);
    m_mm_mod_wrong = new MissingMassModule(m_outdir,"MissingMassWrong");
    m_modules.push_back(m_mm_mod_wrong);
    
    m_sel_sig = new Bs2stSelectModule(m_outdir,"Bs2stSelect_Sig");
    m_modules.push_back(m_sel_sig);
    
    m_sel_bkg = new Bs2stSelectModule(m_outdir,"Bs2stSelect_Bkg");
    m_modules.push_back(m_sel_bkg);

    m_sel_sig_right = new Bs2stSelectModule(m_outdir,"Bs2stSelect_Sig_Right");
    m_modules.push_back(m_sel_sig_right);

    m_sel_sig_wrong = new Bs2stSelectModule(m_outdir,"Bs2stSelect_Sig_Wrong");
    m_modules.push_back(m_sel_sig_wrong);

    m_outdir->cd();
      
    m_h_bs2st_m_raw = new TH1F("h_bs2st_m_raw","mass of reco bs2st; M [GeV]",200,5.5,7);
    m_v_out.push_back(m_h_bs2st_m_raw);

    m_h_bs2st_m_2sol = new TH1F("h_bs2st_m_2sol","mass of reco bs2st; M [GeV]",200,5.5,7);
    m_v_out.push_back(m_h_bs2st_m_2sol);
    
    m_h_bs2st_m = new TH1F("h_bs2st_m","mass of reco bs2st; M [GeV]",200,5.5,7);
    m_v_out.push_back(m_h_bs2st_m);

    m_h_bs2st_e = new TH1F("h_bs2st_e","Energy of reco bs2st; E [GeV]",200,0,400);
    m_v_out.push_back(m_h_bs2st_e);
    
    m_h_bs2st_m_cut = new TH1F("h_bs2st_m_cut","mass of reco bs2st; M [GeV]",200,5.5,7);
    m_v_out.push_back(m_h_bs2st_m_cut);

    m_h_b_de_right = new TH1F("h_b_de_right","B+ #DeltaE for best choice",200,-20,20);
    m_v_out.push_back(m_h_b_de_right);
    
    m_h_b_de_wrong = new TH1F("h_b_de_wrong","B+ #DeltaE for best choice",200,-20,20);
    m_v_out.push_back(m_h_b_de_wrong);
    
    AnalysisBase::BaseLoop::initialize();
    
    return 0;
  }    

}
