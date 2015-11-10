#include "bs2st2buk_jpsik_vars.h"
#include "DecayTreeLoop.h"
#include <vector>

class TFile;
class TH2F;
class TH1F;

namespace bs2st_bu2kmutau {

  class bs2st2buk_jpsik_loop : public bs2st2buk_jpsik_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bs2st2buk_jpsik_loop(TTree * tree);

    virtual int initialize();

  private:

    std::vector<bs2st2buk_jpsik::Bs2st> m_v_bs2st;
    std::vector<bs2st2buk_jpsik::Bu> m_v_bu;
    std::vector<bs2st2buk_jpsik::Km> m_v_km;

    std::vector<bs2st2buk_jpsik::Jpsi> m_v_jpsi;
    std::vector<bs2st2buk_jpsik::Mup> m_v_mup;
    std::vector<bs2st2buk_jpsik::Mum> m_v_mum;

    std::vector<bs2st2buk_jpsik::Kp> m_v_kp;


    TH1F * m_h_mmsq;
    TH1F * m_h_be;
    TH1F * m_h_me;
    TH2F * m_h_mmsqvbe;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
