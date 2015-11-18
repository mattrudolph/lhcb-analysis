#include "CommonParticles.h"
class TTree;

namespace bs2st_bu2kmutau {

  namespace bs2st2buk_jpsik {

    class Bs2st : public bs2st_bu2kmutau::Bs2st {
    public:
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
    };

    class Bu : public bs2st_bu2kmutau::Bu {
    public:
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
    };

    class Mu : public bs2st_bu2kmutau::Mu {
    public:
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
    };

    class Kaon : public bs2st_bu2kmutau::Kaon {
    public:
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
    };


    class Jpsi : public AnalysisBase::InterParticle {
    public:
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Bool_t                L0Global_Dec;
      Bool_t                L0Global_TIS;
      Bool_t                L0Global_TOS;
      Bool_t                Hlt1Global_Dec;
      Bool_t                Hlt1Global_TIS;
      Bool_t                Hlt1Global_TOS;
      Bool_t                Hlt1Phys_Dec;
      Bool_t                Hlt1Phys_TIS;
      Bool_t                Hlt1Phys_TOS;
      Bool_t                Hlt2Global_Dec;
      Bool_t                Hlt2Global_TIS;
      Bool_t                Hlt2Global_TOS;
      Bool_t                Hlt2Phys_Dec;
      Bool_t                Hlt2Phys_TIS;
      Bool_t                Hlt2Phys_TOS;
      Double_t              BPVDIRA;
      Double_t              BPVIPCHI2;
      Double_t              BPVLTIME;
      Double_t              BPVVDCHI2;
      Double_t              BPVZ;
      Double_t              ETA;
      Double_t              MIPCHI2DV;
      Double_t              PHI;
      Double_t              PID;
      Double_t              VCHI2PDOF;
    };

  }

  class bs2st2buk_jpsik_vars : public AnalysisBase::EventInfo {

    public:
    bs2st2buk_jpsik::Bs2st  Bs2st;
    bs2st2buk_jpsik::Bu     Bu;
    bs2st2buk_jpsik::Jpsi   Jpsi;
    bs2st2buk_jpsik::Mu     Mup;
    bs2st2buk_jpsik::Mu     Mum;
    bs2st2buk_jpsik::Kaon   Kp;
    bs2st2buk_jpsik::Kaon   Km;

    void attachTree(TTree * tree);

  };
}
