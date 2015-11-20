#include "MissingMassModule.h"
#include "TH2.h"
#include "MissingMass.h"

namespace bs2st_bu2kmutau {

  MissingMassModule::MissingMassModule(TDirectory * parentDir, std::string name) : AnalysisBase::AnalysisModule( parentDir, name) {}

  int MissingMassModule::bookHistograms() {

    m_outdir->cd();

    m_h_nsols = new TH1F("h_nsols","n solutions",3,-0.5,2.5);
    addout(m_h_nsols);      
    
    m_h_mmsq = new TH1F("h_mmsq","missing mass squared",200,-10,10);
    m_v_out.push_back(m_h_mmsq);

    m_h_be = new TH1F("h_be","b+ energy",200,0,400);
    m_v_out.push_back(m_h_be);
    m_h_me = new TH1F("h_me","missing energy",200,-100,300);
    m_v_out.push_back(m_h_me);
    m_h_ve = new TH1F("h_ve","visible energy",200,0,400);
    addout(m_h_ve);
    
    m_h_mmsqvme = new TH2F("h_mmsqvme","missing mass squared v missing energy",200,-100,300,200,-10,10);
    m_v_out.push_back(m_h_mmsqvme);
    m_h_mmsqvbe = new TH2F("h_mmsqvbe","missing mass squared v missing energy",200,-100,300,200,-10,10);
    m_v_out.push_back(m_h_mmsqvbe);

    m_h_disc = new TH1F("h_disc","sqrt(Discriminant) of E_B quadratic; (E_{1} - E_{2})/(E_{1}+E_{2})",200,0,1);
    addout(m_h_disc);
    
    return 0;

  }

  std::vector<double> MissingMassModule::process( const Bu & bu, const Kaon & km, const Mu & mu, const Kaon & kp ) {

    std::vector<double> vmm = missingMassSq( bu, km, mu, kp );
    fillHistograms( vmm, (mu.PE + kp.PE)/1000. );
    
    return vmm;
  }
  
  void MissingMassModule::fillHistograms( const std::vector<double> & vmm, const double & vis_e ) {

    m_h_nsols->Fill( vmm.size() / 2 );
    
    if(vmm.size()==4) {
      m_h_disc->Fill(  ( vmm[0] - vmm[2] )/(vmm[0]+vmm[2]) );
    }
    
    for(size_t i=0; 2*i+1 < vmm.size(); ++i) {
      double miss_e = vmm[2*i];
      double mmsq = vmm[2*i+1];
      
      m_h_mmsq->Fill( mmsq );
      
      m_h_me->Fill(miss_e);
      m_h_ve->Fill(vis_e);
      
      m_h_be->Fill(miss_e + vis_e);
      
      m_h_mmsqvme->Fill( miss_e, mmsq);
      m_h_mmsqvbe->Fill(miss_e+vis_e, mmsq);

    }
  }
  
}
  
