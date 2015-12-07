#include "RhoMuSelectModule.h"
#include "TH1F.h"
#include "TLorentzVector.h"
#include <cmath>

namespace bs2st_bu2rhomunu {

  RhoMuSelectModule::RhoMuSelectModule(TDirectory * parentDir, std::string name) : AnalysisBase::AnalysisModule( parentDir, name ) {}

  int RhoMuSelectModule::bookHistograms() {

    m_outdir->cd();

    //The rho kinematics and selection
    m_h_rho_m = new TH1F("h_rho_m","rho mass; m_{#pi#pi} [MeV]",200,600,1000);
    addout(m_h_rho_m);

    m_h_rho_pt = new TH1F("h_rho_pt","rho pt; p_T [GeV]",200,0,2000);
    addout(m_h_rho_pt);

    m_h_rho_p = new TH1F("h_rho_p","rho p; p [GeV]",200,0,2000);
    addout(m_h_rho_p);

    m_h_rho_eta = new TH1F("h_rho_eta","rho eta; #eta",200,2,10);
    addout(m_h_rho_eta);

    m_h_rho_vchi2 = new TH1F("h_rho_vchi2","rho vchi2; Vtx #Chi^{2}/NDF",200,0,20);
    addout(m_h_rho_vchi2);

    m_h_rho_fdchi2 = new TH1F("h_rho_fdchi2","rho fd chi2; FD #Chi^{2}/NDF",200,0,10);
    addout(m_h_rho_fdchi2);

    //pi kinematics and selection
    m_h_pi_pt = new TH1F("h_pi_pt","pi pt; p_T [GeV]",200,0,2000);
    addout(m_h_pi_pt);

    m_h_pi_p = new TH1F("h_pi_p","pi p; p [GeV]",200,0,2000);
    addout(m_h_pi_p);

    m_h_pi_eta = new TH1F("h_pi_eta","pi eta; #eta",200,2,5);
    addout(m_h_pi_eta);

    m_h_pi_trchi2 = new TH1F("h_pi_trchi2","pion track chi2;#chi^2",200,0,5);
    addout(m_h_pi_trchi2);

    m_h_pi_trghost = new TH1F("h_pi_trghost","pion ghost prob; Ghost Prob.",200,0,1);
    addout(m_h_pi_trghost);

    m_h_pi_pidk = new TH1F("h_pi_pidk","pi pidk; PIDk",200,-50,50);
    addout(m_h_pi_pidk);

    //mu kinematics and selection
    m_h_mu_pt = new TH1F("h_mu_pt","mu pt; p_T [GeV]",200,0,2000);
    addout(m_h_mu_pt);

    m_h_mu_p = new TH1F("h_mu_p","mu p; p [GeV]",200,0,2000);
    addout(m_h_mu_p);

    m_h_mu_eta = new TH1F("h_mu_eta","mu eta; #eta",200,2,5);
    addout(m_h_mu_eta);

    m_h_mu_trchi2 = new TH1F("h_mu_trchi2","muon track chi2;#chi^2",200,0,5);
    addout(m_h_mu_trchi2);

    m_h_mu_trghost = new TH1F("h_mu_trghost","muon ghost prob; Ghost Prob.",200,0,1);
    addout(m_h_mu_trghost);

    //combination
    m_h_rhomu_m = new TH1F("h_rhomu_m","rhomu mass; m_{#mu#pi#pi} [MeV]",200,600,1000);
    addout(m_h_rhomu_m);

    m_h_rhomu_pt = new TH1F("h_rhomu_pt","rhomu pt; p_T [GeV]",200,0,2000);
    addout(m_h_rhomu_pt);

    m_h_rhomu_p = new TH1F("h_rhomu_p","rhomu p; p [GeV]",200,0,2000);
    addout(m_h_rhomu_p);

    m_h_rhomu_eta = new TH1F("h_rhomu_eta","rhomu eta; #eta",200,2,10);
    addout(m_h_rhomu_eta);

    m_h_rhomu_vchi2 = new TH1F("h_rhomu_vchi2","rhomu vchi2; Vtx #Chi^{2}/NDF",200,0,20);
    addout(m_h_rhomu_vchi2);

    return 0;
  }

  void RhoMuSelectModule::fillHistograms( const Bu & rhomu, const Rho & rho, const Pip & pi1, const Pim & pi2, const Mu & mu ) {


  }

}
