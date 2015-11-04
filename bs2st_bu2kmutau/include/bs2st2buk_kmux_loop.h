#include "bs2st2buk_kmux_vars.h"
#include "DecayTreeLoop.h"
#include <vector>

namespace bs2st_bu2kmutau {

  class bs2st2buk_kmux_loop : public bs2st2buk_kmux_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bs2st2buk_kmux_loop(TTree * tree);

  private:

    std::vector<bs2st2buk_kmux::Bs2st> m_v_bs2st;
    std::vector<bs2st2buk_kmux::Bu> m_v_bu;
    std::vector<bs2st2buk_kmux::Mu> m_v_mu;
    std::vector<bs2st2buk_kmux::Kp> m_v_kp;
    std::vector<bs2st2buk_kmux::Km> m_v_km;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
