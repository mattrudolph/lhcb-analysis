#include "AnalysisModule.h"

namespace AnalysisBase {

  AnalysisModule::AnalysisModule(TDirectory * parentDir, std::string name) : m_name(name) {

    if(parentDir == 0) {
      m_outdir = 0;
    }
    
    m_outdir = parentDir->mkdir(name.c_str());

  }

  int AnalysisModule::writeHistograms() {

    int ret = 0;
    
    if(m_outdir) {
      m_outdir->cd();
      for( size_t i =0; i< m_v_out.size(); ++i) {
        if( m_v_out[i]->Write() == 0 ) {
          ret += 1;
        }
      }
    } else {
      ret = -1;
    }

    return ret;
    
  }
  
}
