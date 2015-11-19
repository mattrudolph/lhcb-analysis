

#include "bs2st2buk_jpsik_loop.h"
#include "MissingMass.h"
#include "MissingMassModule.h"
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

      m_mm_mod->process( m_v_bs2st[i], m_v_bu[i], m_v_km[i], m_v_mup[i], m_v_kp[i] );
      m_mm_mod->process( m_v_bs2st[i], m_v_bu[i], m_v_km[i], m_v_mum[i], m_v_kp[i] );

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

    return 0;
  }    

}
