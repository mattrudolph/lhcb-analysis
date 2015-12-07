#ifndef BS2STBU2RHOMUNU_PARTICLES_H
#define BS2STBU2RHOMUNU_PARTICLES_H

#include "Particles.h"

namespace bs2st_bu2rhomunu {

  class Bs2st : public AnalysisBase::MotherParticle {
  public:
    Double_t              BPVDIRA;
    Double_t              BPVIPCHI2;
    Double_t              ETA;
    Double_t              MIPCHI2DV;
    Double_t              PHI;
    Double_t              PID;
    Double_t              VCHI2PDOF;
  };

  class Bu : public AnalysisBase::InterParticle {
  public:
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

  class Rho : public AnalysisBase::InterParticle {
  public:
    Double_t              BPVDIRA;
    Double_t              ETA;
    Double_t              MIPCHI2DV;
    Double_t              PHI;
    Double_t              PID;
    Double_t              VCHI2PDOF;
  };

  class Pip : public AnalysisBase::StableParticle {
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
    Double_t              ETA;
    Double_t              MIPCHI2DV;
    Double_t              PHI;
    Double_t              PID;
    Double_t              TRCHI2DOF;
    Double_t              TRGHOSTPROB;
  };

  class Pim : public AnalysisBase::StableParticle {
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
    Double_t              ETA;
    Double_t              MIPCHI2DV;
    Double_t              PHI;
    Double_t              PID;
    Double_t              TRCHI2DOF;
    Double_t              TRGHOSTPROB;
  };

  class Mu : public AnalysisBase::StableParticle {
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
    Double_t              BPVZ;
    Double_t              ETA;
    Double_t              MIPCHI2DV;
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
    Double_t              BPVIPCHI2;
    Double_t              BPVZ;
    Double_t              ETA;
    Double_t              MIPCHI2DV;
    Double_t              PHI;
    Double_t              PID;
    Double_t              TRCHI2DOF;
    Double_t              TRGHOSTPROB;
  };

}

#endif
