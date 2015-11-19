#ifndef ANALYSISMODULE_H
#define ANALYSISMODULE_H

#include "TDirectory.h"
#include <string>

namespace AnalysisBase {

  class AnalysisModule {

  public:

    AnalysisModule(TDirectory * parentDir, std::string name = "AnalysisModule");
    virtual ~AnalysisModule() {}

    virtual int bookHistograms() = 0;
    virtual int writeHistograms();

  protected:

    //My name
    std::string m_name;
    
    //Output file or directory for histograms
    TDirectory * m_outdir;

    //This keeps track of things I want to write out
    std::vector<TObject*> m_v_out;
    
  };

}
    
#endif
