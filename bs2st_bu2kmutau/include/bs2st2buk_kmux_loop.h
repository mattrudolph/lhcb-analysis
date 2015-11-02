#include "bs2st2buk_kmux_mcVars.h"
#include "BaseLoop.h"

namespace bs2st_bu2kmutau {

  class bs2st2buk_kmux_loop : public bs2st2buk_kmux_mcVars, public AnalysisBase::BaseLoop {

  public:
    bs2st2buk_kmux_loop(TTree * tree);

  private:
    //have to implement execute
    virtual int execute();


  };

}
