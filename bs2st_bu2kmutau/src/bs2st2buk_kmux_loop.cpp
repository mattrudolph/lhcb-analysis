

#include "bs2st2buk_kmux_loop.h"
#include <iostream>

namespace bs2st_bu2kmutau {

  bs2st2buk_kmux_loop::bs2st2buk_kmux_loop(TTree * tree) : AnalysisBase::BaseLoop(tree) {

    attachTree(m_tree);

  }

  int bs2st2buk_kmux_loop::execute() {

    std::cout << "eventNumber = " << eventNumber << std::endl;

    return 0;
  }

}
