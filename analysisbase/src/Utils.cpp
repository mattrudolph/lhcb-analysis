

#include "Utils.h"
#include "Particles.h"
#include <iostream>

namespace AnalysisBase {

  bool isMotherDaughter( const MotherParticle & p1, const StableParticle & p2) {
    return p1.ENDVERTEX_X == p2.ORIVX_X && p1.ENDVERTEX_Y == p2.ORIVX_Y && p1.ENDVERTEX_Z == p2.ORIVX_Z ;
  }



}
