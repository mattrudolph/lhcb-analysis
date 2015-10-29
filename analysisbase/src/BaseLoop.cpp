

#include "BaseLoop.h"
#include <iostream>

namespace AnalysisBase {

  BaseLoop::BaseLoop(TChain * chain) : m_chain(chain) {

    m_idx = 5;

  }

  void BaseLoop::printIdx() {

    std::cout << m_idx << std::endl;

  }

}
