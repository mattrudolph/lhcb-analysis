#include <vector>

namespace AnalysisBase {
  class MotherParticle;
  class InterParticle;
  class Particle;
}

namespace bs2st_bu2kmutau {

  ///Calculate missing mass from B+ decay for B_s2^* -> B+ K-
  ///Returns MissingEnergy1, MM1, MissingEnergy2, MM2 in vector
  std::vector<double> missingMassSq( const AnalysisBase::MotherParticle & bs2st, const AnalysisBase::InterParticle & bu, const AnalysisBase::Particle & km, const AnalysisBase::Particle & mu, const AnalysisBase::Particle & kp );

}
