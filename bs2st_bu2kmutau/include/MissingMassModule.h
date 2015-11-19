#ifndef MISSINGMASSMODULE_H
#define MISSINGMASSMODULE_H

#include "AnalysisModule.h"
#include "CommonParticles.h"
#include <vector>

class TH1F;
class TH2F;

namespace bs2st_bu2kmutau {

  class MissingMassModule : public AnalysisBase::AnalysisModule {

  public:
    
    MissingMassModule(TDirectory * parentDir, std::string name = "MissingMassModule");

    virtual int bookHistograms();

    std::vector<double> process( const Bs2st & bs2st, const Bu & bu, const Kaon & km, const Mu & mu, const Kaon & kp );

    void fillHistograms(double mmsq, double miss_e, double vis_e);
    
  private:

    TH1F * m_h_mmsq;
    TH1F * m_h_mmsq_cut;
    TH1F * m_h_be;
    TH1F * m_h_me;
    TH2F * m_h_mmsqvme;
    TH2F * m_h_mmsqvbe;

  };
    
}

#endif