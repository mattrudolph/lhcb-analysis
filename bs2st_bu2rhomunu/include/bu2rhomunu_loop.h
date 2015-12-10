#include "bs2st2buk_rhomunu_vars.h"
#include "DecayTreeLoop.h"
#include <vector>

namespace bs2st_bu2rhomunu {

  class RhoMuSelectModule;

  class bu2rhomunu_loop : public bs2st2buk_rhomunu_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bu2rhomunu_loop(TTree * tree, TDirectory * parentdir, std::string name="bu2rhomunu_loop");

    virtual int initialize();

  private:

    std::vector<bs2st_bu2rhomunu::Bu> m_v_bu;
    std::vector<bs2st_bu2rhomunu::Rho> m_v_rho;
    std::vector<bs2st_bu2rhomunu::Pip> m_v_pip;
    std::vector<bs2st_bu2rhomunu::Pim> m_v_pim;
    std::vector<bs2st_bu2rhomunu::Mu> m_v_mu;

    RhoMuSelectModule * m_rhomu_mod;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
