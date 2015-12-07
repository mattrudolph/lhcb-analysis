#ifndef RHOMUSELECTMODULE_H
#define RHOMUSELECTMODULE_H

#include "AnalysisModule.h"
#include "Bs2st_bu2rhomunuParticles.h"

class TH1F;

namespace bs2st_bu2rhomunu {

  class RhoMuSelectModule : public AnalysisBase::AnalysisModule {

  public:

    RhoMuSelectModule(TDirectory * parentDir, std::string name = "RhoMuSelectModule");

    virtual int bookHistograms();

    void fillHistograms( const Bu & rhomu, const Rho & rho, const Pip & pi1, const Pim & pi2, const Mu & mu );

  private:

    TH1F * m_h_rho_m;
    TH1F * m_h_rho_pt;
    TH1F * m_h_rho_p;
    TH1F * m_h_rho_eta;
    TH1F * m_h_rho_vchi2;
    TH1F * m_h_rho_fdchi2;

    TH1F * m_h_pi_pt;
    TH1F * m_h_pi_p;
    TH1F * m_h_pi_eta;
    TH1F * m_h_pi_trchi2;
    TH1F * m_h_pi_trghost;
    TH1F * m_h_pi_pidk;

    TH1F * m_h_mu_pt;
    TH1F * m_h_mu_p;
    TH1F * m_h_mu_eta;
    TH1F * m_h_mu_trchi2;
    TH1F * m_h_mu_trghost;

    TH1F * m_h_rhomu_m;
    TH1F * m_h_rhomu_pt;
    TH1F * m_h_rhomu_p;
    TH1F * m_h_rhomu_eta;
    TH1F * m_h_rhomu_vchi2;

  };
}

#endif
