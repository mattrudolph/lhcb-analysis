
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

}
#endif
