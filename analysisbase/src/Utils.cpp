#include "Utils.h"
#include "Particles.h"
#include <iostream>
#include <algorithm>

namespace AnalysisBase {

  bool isMotherDaughter( const MotherParticle & p1, const StableParticle & p2) {
    return p1.ENDVERTEX_X == p2.ORIVX_X && p1.ENDVERTEX_Y == p2.ORIVX_Y && p1.ENDVERTEX_Z == p2.ORIVX_Z ;
  }


  //Pass argv and argv+argc, and the string you are looking for
  const char* cmdParser::getCmdOption(const std::string & option, const char * def) {
    char ** itr = std::find(m_begin, m_end, option);
    if (itr != m_end && ++itr != m_end)
    {
        return *itr;
    }
    return def;
  }

  bool cmdParser::cmdOptionExists(const std::string& option) {
    return std::find(m_begin, m_end, option) != m_end;
  }

}
