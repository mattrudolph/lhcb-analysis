#include "RhoMuSelectModule.h"
#include "TH1F.h"
#include "TLorentzVector.h"
#include <cmath>

namespace bs2st_bu2rhomunu {

  RhoMuSelectModule::RhoMuSelectModule(TDirectory * parentDir, std::string name) : AnalysisBase::AnalysisModule( parentDir, name ) {}

  int RhoMuSelectModule::bookHistograms() {

    m_outdir->cd();

    //The rho kinematics and selection
    m_h_rho_m = new TH1F("h_rho_m","rho mass; m_{#pi#pi} [MeV]",300,300,1200);
    addout(m_h_rho_m);

    m_h_rho_pt = new TH1F("h_rho_pt","rho pt; p_T [GeV]",200,0,20);
    addout(m_h_rho_pt);

    m_h_rho_p = new TH1F("h_rho_p","rho p; p [GeV]",200,0,100);
    addout(m_h_rho_p);

    m_h_rho_eta = new TH1F("h_rho_eta","rho eta; #eta",200,2,10);
    addout(m_h_rho_eta);

    m_h_rho_vchi2 = new TH1F("h_rho_vchi2","rho vchi2; Vtx #Chi^{2}/NDF",200,0,20);
    addout(m_h_rho_vchi2);

    m_h_rho_fdchi2 = new TH1F("h_rho_fdchi2","rho fd chi2; FD #Chi^{2}/NDF",200,0,10);
    addout(m_h_rho_fdchi2);

    //pi kinematics and selection
    m_h_pi_ptmin = new TH1F("h_pi_ptmin","min pi pt; p_T [GeV]",200,0,20);
    addout(m_h_pi_ptmin);

    m_h_pi_pmin = new TH1F("h_pi_pmin","min pi p; p [GeV]",200,0,100);
    addout(m_h_pi_pmin);

    m_h_pi_ptmax = new TH1F("h_pi_ptmax","max pi pt; p_T [GeV]",200,0,20);
    addout(m_h_pi_ptmax);

    m_h_pi_pmax = new TH1F("h_pi_pmax","max pi p; p [GeV]",200,0,100);
    addout(m_h_pi_pmax);
    
    m_h_pi_eta = new TH1F("h_pi_eta","pi eta; #eta",200,2,5);
    addout(m_h_pi_eta);

    m_h_pi_trchi2 = new TH1F("h_pi_trchi2","pion track chi2;#chi^2",200,0,5);
    addout(m_h_pi_trchi2);

    m_h_pi_trghost = new TH1F("h_pi_trghost","pion ghost prob; Ghost Prob.",200,0,1);
    addout(m_h_pi_trghost);

    m_h_pi_pidk = new TH1F("h_pi_pidk","pi pidk; PIDk",200,-50,50);
    addout(m_h_pi_pidk);

    //mu kinematics and selection
    m_h_mu_pt = new TH1F("h_mu_pt","mu pt; p_T [GeV]",200,0,20);
    addout(m_h_mu_pt);

    m_h_mu_p = new TH1F("h_mu_p","mu p; p [GeV]",200,0,100);
    addout(m_h_mu_p);

    m_h_mu_eta = new TH1F("h_mu_eta","mu eta; #eta",200,2,5);
    addout(m_h_mu_eta);

    m_h_mu_trchi2 = new TH1F("h_mu_trchi2","muon track chi2;#chi^2",200,0,5);
    addout(m_h_mu_trchi2);

    m_h_mu_trghost = new TH1F("h_mu_trghost","muon ghost prob; Ghost Prob.",200,0,1);
    addout(m_h_mu_trghost);

    //combination
    m_h_rhomu_m = new TH1F("h_rhomu_m","rhomu mass; m_{#mu#pi#pi} [MeV]",200,1,10);
    addout(m_h_rhomu_m);

    m_h_rhomu_pt = new TH1F("h_rhomu_pt","rhomu pt; p_T [GeV]",200,0,20);
    addout(m_h_rhomu_pt);

    m_h_rhomu_p = new TH1F("h_rhomu_p","rhomu p; p [GeV]",200,0,200);
    addout(m_h_rhomu_p);

    m_h_rhomu_eta = new TH1F("h_rhomu_eta","rhomu eta; #eta",200,2,10);
    addout(m_h_rhomu_eta);

    m_h_rhomu_vchi2 = new TH1F("h_rhomu_vchi2","rhomu vchi2; Vtx #Chi^{2}/NDF",200,0,50);
    addout(m_h_rhomu_vchi2);
    
    m_h_rhomu_pvdchi2 = new TH1F("h_rhomu_pvdchi2","rhomu pvdchi2; #Chi^{2}/NDF",200,100,900);
    addout(m_h_rhomu_pvdchi2);

    return 0;
  }

  void RhoMuSelectModule::fillHistograms( const Bu & rhomu, const Rho & rho, const Pip & pi1, const Pim & pi2, const Mu & mu ) {


    m_h_rho_m->Fill( rho.M );
    m_h_rho_pt->Fill( rho.PT/1000. );
    m_h_rho_p->Fill( rho.P/1000. );
    m_h_rho_eta->Fill( rho.ETA );
    m_h_rho_vchi2->Fill( rho.VCHI2PDOF );
    m_h_rho_fdchi2->Fill( rho.FDCHI2_ORIVX );

    m_h_mu_pt->Fill( mu.PT/1000. );
    m_h_mu_p->Fill( mu.P/1000. );
    m_h_mu_eta->Fill( mu.ETA );
    m_h_mu_trchi2->Fill( mu.TRCHI2DOF );
    m_h_mu_trghost->Fill( mu.TRGHOSTPROB );

    m_h_pi_ptmin->Fill( std::min( pi1.PT, pi2.PT )/1000. );
    m_h_pi_pmin->Fill( std::min( pi1.P, pi2.P )/1000. );
    m_h_pi_ptmax->Fill( std::max( pi1.PT, pi2.PT )/1000. );
    m_h_pi_pmax->Fill( std::max( pi1.P, pi2.P )/1000. );
    m_h_pi_eta->Fill( pi1.ETA );
    m_h_pi_eta->Fill( pi2.ETA );
    m_h_pi_trchi2->Fill( std::max( pi1.TRCHI2DOF, pi2.TRCHI2DOF ) );
    m_h_pi_trghost->Fill( std::max(pi1.TRGHOSTPROB,pi2.TRGHOSTPROB) );
    m_h_pi_pidk->Fill( std::max( pi1.PIDK, pi2.PIDK ) );
    
    m_h_rhomu_m->Fill( rhomu.M/1000. );
    m_h_rhomu_pt->Fill( rhomu.PT/1000. );
    m_h_rhomu_p->Fill( rhomu.P/1000. );
    m_h_rhomu_eta->Fill( rhomu.ETA );
    m_h_rhomu_vchi2->Fill( rhomu.VCHI2PDOF );
    m_h_rhomu_pvdchi2->Fill( rhomu.BPVVDCHI2 );
  }

}
