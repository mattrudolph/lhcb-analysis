

#include "bs2st2buk_kmux_loop.h"
#include "MissingMass.h"
#include "TFile.h"
#include "TH2.h"
#include <iostream>

namespace bs2st_bu2kmutau {

  bs2st2buk_kmux_loop::bs2st2buk_kmux_loop(TTree * tree) : AnalysisBase::DecayTreeLoop(tree) {

    attachTree(m_tree);

  }

  int bs2st2buk_kmux_loop::cacheCandidate() {
    std::cout << Bu.ENDVERTEX_Z << std::endl;
    std::cout << Bu.ENDVERTEX_Z - Bu.OWNPV_Z << std::endl;
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

      std::vector<double> mmret = missingMassSq( m_v_bs2st[i], m_v_bu[i], m_v_km[i], m_v_mu[i], m_v_kp[i] );
      if(mmret.size() == 0)
        continue;
      m_h_be->Fill(mmret[0]);
      m_h_be->Fill(mmret[1]);

      m_h_me->Fill(mmret[0] - m_v_mu[i].PE/1000. - m_v_kp[i].PE/1000.);
      m_h_me->Fill(mmret[1] - m_v_mu[i].PE/1000. - m_v_kp[i].PE/1000.);

      m_h_mmsq->Fill( mmret[2] );
      m_h_mmsq->Fill( mmret[3] );

      m_h_mmsqvbe->Fill(mmret[0],mmret[2]);
      m_h_mmsqvbe->Fill(mmret[1],mmret[3]);
    }
    return 0;
  }

  int bs2st2buk_kmux_loop::initialize() {

    m_outfile = new TFile("test.root","recreate");

    m_h_mmsq = new TH1F("h_mmsq","missing mass squared",200,-10,10);
    m_v_out.push_back(m_h_mmsq);

    m_h_be = new TH1F("h_be","b+ energy",200,0,400);
    m_v_out.push_back(m_h_be);
    m_h_me = new TH1F("h_me","missing energy",200,-100,300);
    m_v_out.push_back(m_h_me);

    m_h_mmsqvbe = new TH2F("h_mmsqvbe","missing mass squared v b+ energy",200,0,400,200,-10,10);
    m_v_out.push_back(m_h_mmsqvbe);

    return 0;
  }    

}
