

#include "Utils.h"
#include <iostream>

namespace AnalysisBase {

  Test::Test() {

    m_idx = 4;

  }

  void Test::run() {

    std::cout << m_idx << std::endl;

  }

}
