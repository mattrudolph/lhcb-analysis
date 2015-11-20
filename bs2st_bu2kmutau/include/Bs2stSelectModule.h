#ifndef BS2STSELECTMODULE_H
#define BS2STSELECTMODULE_H

#include "AnalysisModule.h"
#include "CommonParticles.h"

class TH1F;

namespace bs2st_bu2kmutau {

  class Bs2stSelectModule : public AnalysisBase::AnalysisModule {

  public:

    Bs2stSelectModule(TDirectory * parentDir, std::string name = "Bs2stSelectModule");

    virtual int bookHistograms();

    void fillHistograms( const Kaon & k, const Bu & bu, const double & be , const double & me );

  private:

    TH1F * m_h_k_pt;
    TH1F * m_h_k_eta;
    TH1F * m_h_k_pid;
    TH1F * m_h_k_ipchi2;
    TH1F * m_h_k_trchi2;
    TH1F * m_h_k_trghost;

    TH1F * m_h_kb_cos;

    TH1F * m_h_b_e;
    TH1F * m_h_b_pt;
    TH1F * m_h_b_eta;

    TH1F * m_h_m_e;
    TH1F * m_h_v_e;
    
    TH1F * m_h_bs2st_e;
    TH1F * m_h_bs2st_pt;
    TH1F * m_h_bs2st_eta;

  };
}

#endif
