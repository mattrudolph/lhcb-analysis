#include "bs2st2buk_kmux_vars.h"
#include "DecayTreeLoop.h"
#include <vector>


namespace bs2st_bu2kmutau {

  class MissingMassModule;
  
  class bs2st2buk_kmux_loop : public bs2st2buk_kmux_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bs2st2buk_kmux_loop(TTree * tree, TDirectory * parentdir, std::string name="bs2st2buk_kmux_loop");

    virtual int initialize();

  private:

    std::vector<bs2st_bu2kmutau::Bs2st> m_v_bs2st;
    std::vector<bs2st_bu2kmutau::Bu> m_v_bu;
    std::vector<bs2st_bu2kmutau::Mu> m_v_mu;
    std::vector<bs2st_bu2kmutau::Kaon> m_v_kp;
    std::vector<bs2st_bu2kmutau::Kaon> m_v_km;

    MissingMassModule * m_mm_mod;
    MissingMassModule * m_mm_cutmod;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
