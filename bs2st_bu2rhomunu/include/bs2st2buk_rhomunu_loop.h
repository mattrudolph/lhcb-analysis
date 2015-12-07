#include "bs2st2buk_rhomunu_vars.h"
#include "DecayTreeLoop.h"
#include <vector>


namespace bs2st_bu2kmutau {
  class MissingMassModule;
}

namespace bs2st_bu2rhomunu {
  
  class bs2st2buk_rhomunu_loop : public bs2st2buk_rhomunu_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bs2st2buk_rhomunu_loop(TTree * tree, TDirectory * parentdir, std::string name="bs2st2buk_rhomunu_loop");

    virtual int initialize();

  private:

    std::vector<bs2st_bu2rhomunu::Bs2st> m_v_bs2st;
    std::vector<bs2st_bu2rhomunu::Bu> m_v_bu;
    std::vector<bs2st_bu2rhomunu::Rho> m_v_rho;
    std::vector<bs2st_bu2rhomunu::Pip> m_v_pip;
    std::vector<bs2st_bu2rhomunu::Pim> m_v_pim;
    std::vector<bs2st_bu2rhomunu::Mu> m_v_mu;
    std::vector<bs2st_bu2rhomunu::Km> m_v_km;

    bs2st_bu2kmutau::MissingMassModule * m_mm_mod;
    bs2st_bu2kmutau::MissingMassModule * m_mm_mod_cut;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
