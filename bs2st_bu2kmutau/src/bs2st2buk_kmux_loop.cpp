

#include "bs2st2buk_kmux_loop.h"
#include <iostream>

namespace bs2st_bu2kmutau {

  bs2st2buk_kmux_loop::bs2st2buk_kmux_loop(TTree * tree) : AnalysisBase::DecayTreeLoop(tree) {

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
    std::cout << "In execute" << std::endl;

    std::cout << "eventNumber = " << eventNumber << std::endl;

    for(size_t i=0; i<m_v_bs2st.size(); ++i ) 
      std::cout << m_v_bs2st[i].M << std::endl;

    return 0;
  }

}
