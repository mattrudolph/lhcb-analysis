#include "bs2st2buk_kmux_vars.h"
#include "DecayTreeLoop.h"
#include <vector>

class TFile;
class TH2F;
class TH1F;

namespace bs2st_bu2kmutau {

  class bs2st2buk_kmux_loop : public bs2st2buk_kmux_vars, public AnalysisBase::DecayTreeLoop {

  public:
    bs2st2buk_kmux_loop(TTree * tree);

    virtual int initialize();

  private:

    std::vector<bs2st_bu2kmutau::Bs2st> m_v_bs2st;
    std::vector<bs2st_bu2kmutau::Bu> m_v_bu;
    std::vector<bs2st_bu2kmutau::Mu> m_v_mu;
    std::vector<bs2st_bu2kmutau::Kaon> m_v_kp;
    std::vector<bs2st_bu2kmutau::Kaon> m_v_km;

    TH1F * m_h_mmsq;
    TH1F * m_h_mmsq_cut;
    TH1F * m_h_be;
    TH1F * m_h_me;
    TH2F * m_h_mmsqvme;
    TH2F * m_h_mmsqvbe;

    //have to implement execute and cache
    virtual int cacheCandidate();
    virtual int clearCache();
    virtual int execute();


  };

}
