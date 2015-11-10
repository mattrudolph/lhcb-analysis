#include <vector>

namespace AnalysisBase {
  class MotherParticle;
  class InterParticle;
  class StableParticle;
}

namespace bs2st_bu2kmutau {

  ///Calculate missing mass from B+ decay for B_s2^* -> B+ K-
  std::vector<double> missingMassSq( const AnalysisBase::MotherParticle & bs2st, const AnalysisBase::InterParticle & bu, const AnalysisBase::StableParticle & km, const AnalysisBase::StableParticle & mu, const AnalysisBase::StableParticle & kp );

}
