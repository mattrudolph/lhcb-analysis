#include "CommonParticles.h"

class TTree;

namespace bs2st_bu2kmutau {

  class bs2st2buk_kmux_vars : public AnalysisBase::EventInfo {

    public:

    bs2st_bu2kmutau::Bs2st  Bs2st;
    bs2st_bu2kmutau::Bu     Bu;
    bs2st_bu2kmutau::Mu     Mu;
    bs2st_bu2kmutau::Kaon   Kp;
    bs2st_bu2kmutau::Kaon   Km;

    void attachTree(TTree * tree);

  };
}
