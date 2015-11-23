#ifndef BS2STBU2RHOMUNU_VARS_H
#define BS2STBU2RHOMUNU_VARS_H

#include "Bs2st_bu2rhomunuParticles.h"
class TTree;

namespace bs2st_bu2rhomunu {

  namespace bs2st2buk_rhomunu {

  }

  class bs2st2buk_rhomunu_vars : public AnalysisBase::EventInfo {

    public:
    bs2st_bu2rhomunu::Bs2st         Bs2st;
    bs2st_bu2rhomunu::Bu            Bu;
    bs2st_bu2rhomunu::Rho           Rho;
    bs2st_bu2rhomunu::Pip           Pip;
    bs2st_bu2rhomunu::Pim           Pim;
    bs2st_bu2rhomunu::Mu            Mu;
    bs2st_bu2rhomunu::Km            Km;


    void attachTree(TTree * tree);

  };
}

#endif
