#include "Bs2stSelectModule.h"
#include "TH1F.h"
#include "TLorentzVector.h"
#include <cmath>

namespace bs2st_bu2kmutau {

  Bs2stSelectModule::Bs2stSelectModule(TDirectory * parentDir, std::string name) : AnalysisBase::AnalysisModule( parentDir, name ) {}

  int Bs2stSelectModule::bookHistograms() {

    m_outdir->cd();


    //The prompt kaon we are attaching
    m_h_k_pt = new TH1F("h_k_pt","prompt kaon pt;p_{T} [GeV]",200,0,10);
    addout(m_h_k_pt);

    m_h_k_eta = new TH1F("h_k_eta","prompt kaon eta;#eta",200,2,5);
    addout(m_h_k_eta);

    m_h_k_pid = new TH1F("h_k_pid","prompt kaon PIDK; PIDK",200,0,100);
    addout(m_h_k_pid);

    m_h_k_ipchi2 = new TH1F("h_k_ipchi2","prompt kaon IPCHI2; #chi^2",200,0,50);
    addout(m_h_k_ipchi2);

    m_h_k_trchi2 = new TH1F("h_k_trchi2","prompt kaon track chi2;#chi^2",200,0,5);
    addout(m_h_k_trchi2);

    m_h_k_trghost = new TH1F("h_k_trghost","prompt kaon ghost prob; Ghost Prob.",200,0,1);
    addout(m_h_k_trghost);

    //Combination with the B+ vertex after constraining to Bs2st decay

    m_h_kb_cos = new TH1F("h_kb_cos","cosTheta in lab btwn K and B; cos#theta",200,0.9,1);
    addout(m_h_kb_cos);

    m_h_b_e = new TH1F("h_b_e","reco B+ energy; E [GeV]",200,0,300);
    addout(m_h_b_e);

    m_h_b_pt = new TH1F("h_b_pt","reco B+ p_T; p_{T} [GeV]",200,0,50);
    addout(m_h_b_pt);

    m_h_b_eta = new TH1F("h_b_eta","reco B+ eta; #eta",200,0,10);
    addout(m_h_b_eta);

    m_h_bs2st_e = new TH1F("h_bs2st_e","reco B_s2^* energy; E [GeV]",200,0,300);
    addout(m_h_bs2st_e);

    m_h_bs2st_pt = new TH1F("h_bs2st_pt","reco B_s2^* p_T; p_{T} [GeV]",200,0,50);
    addout(m_h_bs2st_pt);

    m_h_bs2st_eta = new TH1F("h_bs2st_eta","reco B_s2^* eta; #eta",200,0,10);
    addout(m_h_bs2st_eta);

    return 0;
  }


  //Give energy in GeV!
  void Bs2stSelectModule::fillHistograms( const Kaon & k, const Bu & bu, const double & be ) {

    const double mbu = 5.27929; //+-0.00015
    double p = std::sqrt( be*be - mbu*mbu);

    double bdx = (bu.ENDVERTEX_X - bu.OWNPV_X);
    double bdy = (bu.ENDVERTEX_Y - bu.OWNPV_Y);
    double bdz = (bu.ENDVERTEX_Z - bu.OWNPV_Z);
    double l = std::sqrt(bdx*bdx + bdy*bdy + bdz*bdz);    

    double pbol = p/l;
    TLorentzVector pb( bdx*pbol, bdy*pbol, bdz*pbol, be );

    TLorentzVector pk( k.PX/1000., k.PY/1000., k.PZ/1000., k.PE/1000.);

    TLorentzVector pbs2st = pb + pk;

    m_h_k_pt->Fill( pk.Pt() );
    m_h_k_eta->Fill( pk.Eta() );
    m_h_k_pid->Fill( k.PIDK );
    m_h_k_ipchi2->Fill( k.BPVIPCHI2 );
    m_h_k_trchi2->Fill( k.TRCHI2DOF );
    m_h_k_trghost->Fill( k.TRGHOSTPROB );

    m_h_kb_cos->Fill( pk.Vect().Unit().Dot( pb.Vect().Unit() ) );

    m_h_b_e->Fill( be );
    m_h_b_pt->Fill( pb.Pt() );
    m_h_b_eta->Fill( pb.Eta() );

    m_h_bs2st_e->Fill( pbs2st.E() );
    m_h_bs2st_pt->Fill( pbs2st.Pt() );
    m_h_bs2st_eta->Fill( pbs2st.Eta() );

  }

}
