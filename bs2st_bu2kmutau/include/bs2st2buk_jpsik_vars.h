#include "Particles.h"
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

class TTree;

namespace bs2st_bu2kmutau {

  namespace bs2st2buk_jpsik {

    class Bs2st : public AnalysisBase::MotherParticle {
    public:
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              FD_OWNPV;
      Double_t              FDCHI2_OWNPV;
      Double_t              DIRA_OWNPV;
      Double_t              MM;
      Double_t              MMERR;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Double_t              BPVDIRA;
      Double_t              BPVIPCHI2;
      Double_t              ETA;
      Double_t              PHI;
      Double_t              PID;
    };

    class Bu : public AnalysisBase::InterParticle {
    public:
      Double_t              CosTheta;
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              FD_OWNPV;
      Double_t              FDCHI2_OWNPV;
      Double_t              DIRA_OWNPV;
      Double_t              FD_ORIVX;
      Double_t              FDCHI2_ORIVX;
      Double_t              DIRA_ORIVX;
      Double_t              MM;
      Double_t              MMERR;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
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

    class Jpsi : public AnalysisBase::InterParticle {
    public:
      Double_t              CosTheta;
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              FD_OWNPV;
      Double_t              FDCHI2_OWNPV;
      Double_t              DIRA_OWNPV;
      Double_t              FD_ORIVX;
      Double_t              FDCHI2_ORIVX;
      Double_t              DIRA_ORIVX;
      Double_t              MM;
      Double_t              MMERR;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Double_t              ETA;
      Double_t              PHI;
      Double_t              PID;
      Double_t              VCHI2PDOF;
    };

    class Mup : public AnalysisBase::StableParticle {
    public:
      Double_t              MC12TuneV2_ProbNNe;
      Double_t              MC12TuneV2_ProbNNmu;
      Double_t              MC12TuneV2_ProbNNpi;
      Double_t              MC12TuneV2_ProbNNk;
      Double_t              MC12TuneV2_ProbNNp;
      Double_t              MC12TuneV2_ProbNNghost;
      Double_t              MC12TuneV3_ProbNNe;
      Double_t              MC12TuneV3_ProbNNmu;
      Double_t              MC12TuneV3_ProbNNpi;
      Double_t              MC12TuneV3_ProbNNk;
      Double_t              MC12TuneV3_ProbNNp;
      Double_t              MC12TuneV3_ProbNNghost;
      Double_t              CosTheta;
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              PIDe;
      Double_t              PIDmu;
      Double_t              PIDK;
      Double_t              PIDp;
      Double_t              ProbNNe;
      Double_t              ProbNNk;
      Double_t              ProbNNp;
      Double_t              ProbNNpi;
      Double_t              ProbNNmu;
      Double_t              ProbNNghost;
      Bool_t                hasMuon;
      Bool_t                isMuon;
      Bool_t                hasRich;
      Bool_t                hasCalo;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Double_t              BPVZ;
      Double_t              ETA;
      Double_t              MIPCHI2DV;
      Double_t              MM;
      Double_t              PHI;
      Double_t              PID;
      Double_t              TRCHI2DOF;
      Double_t              TRGHOSTPROB;
    };

    class Mum : public AnalysisBase::StableParticle {
    public:
      Double_t              MC12TuneV2_ProbNNe;
      Double_t              MC12TuneV2_ProbNNmu;
      Double_t              MC12TuneV2_ProbNNpi;
      Double_t              MC12TuneV2_ProbNNk;
      Double_t              MC12TuneV2_ProbNNp;
      Double_t              MC12TuneV2_ProbNNghost;
      Double_t              MC12TuneV3_ProbNNe;
      Double_t              MC12TuneV3_ProbNNmu;
      Double_t              MC12TuneV3_ProbNNpi;
      Double_t              MC12TuneV3_ProbNNk;
      Double_t              MC12TuneV3_ProbNNp;
      Double_t              MC12TuneV3_ProbNNghost;
      Double_t              CosTheta;
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              PIDe;
      Double_t              PIDmu;
      Double_t              PIDK;
      Double_t              PIDp;
      Double_t              ProbNNe;
      Double_t              ProbNNk;
      Double_t              ProbNNp;
      Double_t              ProbNNpi;
      Double_t              ProbNNmu;
      Double_t              ProbNNghost;
      Bool_t                hasMuon;
      Bool_t                isMuon;
      Bool_t                hasRich;
      Bool_t                hasCalo;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Double_t              BPVZ;
      Double_t              ETA;
      Double_t              MIPCHI2DV;
      Double_t              MM;
      Double_t              PHI;
      Double_t              PID;
      Double_t              TRCHI2DOF;
      Double_t              TRGHOSTPROB;
    };

    class Kp : public AnalysisBase::StableParticle {
    public:
      Double_t              MC12TuneV2_ProbNNe;
      Double_t              MC12TuneV2_ProbNNmu;
      Double_t              MC12TuneV2_ProbNNpi;
      Double_t              MC12TuneV2_ProbNNk;
      Double_t              MC12TuneV2_ProbNNp;
      Double_t              MC12TuneV2_ProbNNghost;
      Double_t              MC12TuneV3_ProbNNe;
      Double_t              MC12TuneV3_ProbNNmu;
      Double_t              MC12TuneV3_ProbNNpi;
      Double_t              MC12TuneV3_ProbNNk;
      Double_t              MC12TuneV3_ProbNNp;
      Double_t              MC12TuneV3_ProbNNghost;
      Double_t              CosTheta;
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              PIDe;
      Double_t              PIDmu;
      Double_t              PIDK;
      Double_t              PIDp;
      Double_t              ProbNNe;
      Double_t              ProbNNk;
      Double_t              ProbNNp;
      Double_t              ProbNNpi;
      Double_t              ProbNNmu;
      Double_t              ProbNNghost;
      Bool_t                hasMuon;
      Bool_t                isMuon;
      Bool_t                hasRich;
      Bool_t                hasCalo;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Double_t              BPVIPCHI2;
      Double_t              BPVZ;
      Double_t              ETA;
      Double_t              MIPCHI2DV;
      Double_t              MM;
      Double_t              PHI;
      Double_t              PID;
      Double_t              TRCHI2DOF;
      Double_t              TRGHOSTPROB;
    };

    class Km : public AnalysisBase::StableParticle {
    public:
      Double_t              MC12TuneV2_ProbNNe;
      Double_t              MC12TuneV2_ProbNNmu;
      Double_t              MC12TuneV2_ProbNNpi;
      Double_t              MC12TuneV2_ProbNNk;
      Double_t              MC12TuneV2_ProbNNp;
      Double_t              MC12TuneV2_ProbNNghost;
      Double_t              MC12TuneV3_ProbNNe;
      Double_t              MC12TuneV3_ProbNNmu;
      Double_t              MC12TuneV3_ProbNNpi;
      Double_t              MC12TuneV3_ProbNNk;
      Double_t              MC12TuneV3_ProbNNp;
      Double_t              MC12TuneV3_ProbNNghost;
      Double_t              CosTheta;
      Double_t              IP_OWNPV;
      Double_t              IPCHI2_OWNPV;
      Double_t              PIDe;
      Double_t              PIDmu;
      Double_t              PIDK;
      Double_t              PIDp;
      Double_t              ProbNNe;
      Double_t              ProbNNk;
      Double_t              ProbNNp;
      Double_t              ProbNNpi;
      Double_t              ProbNNmu;
      Double_t              ProbNNghost;
      Bool_t                hasMuon;
      Bool_t                isMuon;
      Bool_t                hasRich;
      Bool_t                hasCalo;
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
      Bool_t                Hlt2DiMuonJPsiDecision_Dec;
      Bool_t                Hlt2DiMuonJPsiDecision_TIS;
      Bool_t                Hlt2DiMuonJPsiDecision_TOS;
      Double_t              BPVIPCHI2;
      Double_t              BPVZ;
      Double_t              ETA;
      Double_t              MIPCHI2DV;
      Double_t              MM;
      Double_t              PHI;
      Double_t              PID;
      Double_t              TRCHI2DOF;
      Double_t              TRGHOSTPROB;
    };

  }

  class bs2st2buk_jpsik_vars {

    public:
    UInt_t                nCandidate;
    ULong64_t             totCandidates;
    ULong64_t             EventInSequence;
    UInt_t                BCID;
    Int_t                 BCType;
    UInt_t                OdinTCK;
    UInt_t                L0DUTCK;
    UInt_t                HLT1TCK;
    UInt_t                HLT2TCK;
    ULong64_t             GpsTime;
    Short_t               Polarity;
    Int_t                 nPV;
    Float_t               PVX[100];
    Float_t               PVY[100];
    Float_t               PVZ[100];
    Float_t               PVXERR[100];
    Float_t               PVYERR[100];
    Float_t               PVZERR[100];
    Float_t               PVCHI2[100];
    Float_t               PVNDOF[100];
    Float_t               PVNTRACKS[100];

    bs2st2buk_jpsik::Bs2st  Bs2st;
    bs2st2buk_jpsik::Bu     Bu;
    bs2st2buk_jpsik::Jpsi   Jpsi;
    bs2st2buk_jpsik::Mup    Mup;
    bs2st2buk_jpsik::Mum    Mum;
    bs2st2buk_jpsik::Kp     Kp;
    bs2st2buk_jpsik::Km     Km;

    void attachTree(TTree * tree);

  };
}