#ifndef UTILS_H
#define UTILS_H

namespace AnalysisBase {

  class Particle;
  class MotherParticle;
  class InterParticle;
  class StableParticle;


  bool isMotherDaughter( const MotherParticle & p1, const StableParticle & p2 );



}

#endif
