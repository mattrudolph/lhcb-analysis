#include "bs2st2buk_jpsik_vars.h"
#include "DecayTreeLoop.h"
#include <vector>

class TH1F;

namespace bs2st_bu2kmutau {

  class MissingMassModule;
  class Bs2stSelectModule;

  class bs2st2buk_jpsik_loop : public bs2st2buk_jpsik_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bs2st2buk_jpsik_loop(TTree * tree, TDirectory * parentdir, std::string name="bs2st2buk_jpsik_loop");

    virtual int initialize();

  private:

    std::vector<bs2st2buk_jpsik::Bs2st> m_v_bs2st;
    std::vector<bs2st2buk_jpsik::Bu> m_v_bu;
    std::vector<bs2st2buk_jpsik::Kaon> m_v_km;

    std::vector<bs2st2buk_jpsik::Jpsi> m_v_jpsi;
    std::vector<bs2st2buk_jpsik::Mu> m_v_mup;
    std::vector<bs2st2buk_jpsik::Mu> m_v_mum;

    std::vector<bs2st2buk_jpsik::Kaon> m_v_kp;

    TH1F * m_h_bs2st_m;

    MissingMassModule * m_mm_mod;
    Bs2stSelectModule * m_sel_sig;
    Bs2stSelectModule * m_sel_bkg;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
