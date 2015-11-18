
#ifndef ROOT_Rtypes
#include "Rtypes.h"
#endif

/**
   Basic particle types to be used with decay tree loop variables
*/
#ifndef PARTICLES_H
#define PARTICLES_H

namespace AnalysisBase {

  class Particle {

  public:
    Particle();
    virtual ~Particle() {};

    Double_t              P;
    Double_t              PT;
    Double_t              PE;
    Double_t              PX;
    Double_t              PY;
    Double_t              PZ;
    Double_t              M;
    Double_t              MM;
    Double_t              MMERR;
    Int_t                 ID;


    Double_t              OWNPV_X;
    Double_t              OWNPV_Y;
    Double_t              OWNPV_Z;
    Double_t              OWNPV_XERR;
    Double_t              OWNPV_YERR;
    Double_t              OWNPV_ZERR;
    Double_t              OWNPV_CHI2;
    Int_t                 OWNPV_NDOF;
    Float_t               OWNPV_COV_[3][3];
    Double_t              IP_OWNPV;
    Double_t              IPCHI2_OWNPV;
    Double_t              FD_OWNPV;
    Double_t              FDCHI2_OWNPV;
    Double_t              DIRA_OWNPV;

  };

  //Particle with an end vertex
  class MotherParticle : public Particle {

  public:
    MotherParticle();
    virtual ~MotherParticle() {};
  
    Double_t              ENDVERTEX_X;
    Double_t              ENDVERTEX_Y;
    Double_t              ENDVERTEX_Z;
    Double_t              ENDVERTEX_XERR;
    Double_t              ENDVERTEX_YERR;
    Double_t              ENDVERTEX_ZERR;
    Double_t              ENDVERTEX_CHI2;
    Int_t                 ENDVERTEX_NDOF;
    Float_t               ENDVERTEX_COV_[3][3];

  };

  //Particle with origin vertex
  class StableParticle : public Particle {

  public:
    StableParticle();
    virtual ~StableParticle() {};

    Double_t              ORIVX_X;
    Double_t              ORIVX_Y;
    Double_t              ORIVX_Z;
    Double_t              ORIVX_XERR;
    Double_t              ORIVX_YERR;
    Double_t              ORIVX_ZERR;
    Double_t              ORIVX_CHI2;
    Int_t                 ORIVX_NDOF;
    Float_t               ORIVX_COV_[3][3];
    Double_t              CosTheta;
    Double_t              FD_ORIVX;
    Double_t              FDCHI2_ORIVX;
    Double_t              DIRA_ORIVX;
    Double_t              PIDe;
    Double_t              PIDmu;
    Double_t              PIDK;
    Double_t              PIDp;
  };

  //Particle with both
  //  make special class for this so that methods which operate on particles can more easily enforce what they get
  class InterParticle : public Particle {

  public:
    InterParticle();
    virtual ~InterParticle() {};
  
    Double_t              ORIVX_X;
    Double_t              ORIVX_Y;
    Double_t              ORIVX_Z;
    Double_t              ORIVX_XERR;
    Double_t              ORIVX_YERR;
    Double_t              ORIVX_ZERR;
    Double_t              ORIVX_CHI2;
    Int_t                 ORIVX_NDOF;
    Float_t               ORIVX_COV_[3][3];
    Double_t              CosTheta;
    Double_t              FD_ORIVX;
    Double_t              FDCHI2_ORIVX;
    Double_t              DIRA_ORIVX;
    Double_t              ENDVERTEX_X;
    Double_t              ENDVERTEX_Y;
    Double_t              ENDVERTEX_Z;
    Double_t              ENDVERTEX_XERR;
    Double_t              ENDVERTEX_YERR;
    Double_t              ENDVERTEX_ZERR;
    Double_t              ENDVERTEX_CHI2;
    Int_t                 ENDVERTEX_NDOF;
    Float_t               ENDVERTEX_COV_[3][3];

  };
  class EventInfo {
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
  };
}
#endif
