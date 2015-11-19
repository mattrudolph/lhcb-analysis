#include "MissingMassModule.h"
#include "TH2.h"
#include "MissingMass.h"

namespace bs2st_bu2kmutau {

  MissingMassModule::MissingMassModule(TDirectory * parentDir, std::string name) : AnalysisBase::AnalysisModule( parentDir, name) {}

  int MissingMassModule::bookHistograms() {

    m_outdir->cd();
    
    m_h_mmsq = new TH1F("h_mmsq","missing mass squared",200,-10,10);
    m_v_out.push_back(m_h_mmsq);

    m_h_be = new TH1F("h_be","b+ energy",200,0,400);
    m_v_out.push_back(m_h_be);
    m_h_me = new TH1F("h_me","missing energy",200,-100,300);
    m_v_out.push_back(m_h_me);

    m_h_mmsqvme = new TH2F("h_mmsqvme","missing mass squared v missing energy",200,-100,300,200,-10,10);
    m_v_out.push_back(m_h_mmsqvme);
    m_h_mmsqvbe = new TH2F("h_mmsqvbe","missing mass squared v missing energy",200,-100,300,200,-10,10);
    m_v_out.push_back(m_h_mmsqvbe);

    return 0;

  }

  std::vector<double> MissingMassModule::process( const Bs2st & bs2st, const Bu & bu, const Kaon & km, const Mu & mu, const Kaon & kp ) {

    std::vector<double> vmm = missingMassSq( bs2st, bu, km, mu, kp );
    for(size_t i=0; 2*i+1 < vmm.size(); ++i) {
      fillHistograms( vmm[2*i+1], vmm[2*i], (mu.PE + kp.PE)/1000. );
    }
    
    return vmm;
  }
  
  void MissingMassModule::fillHistograms( double mmsq, double miss_e, double vis_e ) {

    m_h_mmsq->Fill( mmsq );
    
    m_h_me->Fill(miss_e);
    
    m_h_be->Fill(miss_e + vis_e);
      
    m_h_mmsqvme->Fill( miss_e, mmsq);
    m_h_mmsqvbe->Fill(miss_e+vis_e, mmsq);

    
  }
  
}
  
