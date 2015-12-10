#ifndef UTILS_H
#define UTILS_H

#include <string>

namespace AnalysisBase {

  class Particle;
  class MotherParticle;
  class InterParticle;
  class StableParticle;

  bool isMotherDaughter( const MotherParticle & p1, const StableParticle & p2 );


  //For now super simple parser -- could use this class to interface to a new library later without changing executables much
  class cmdParser {
  public:
    cmdParser(int argc, char ** argv) : m_begin(argv), m_end(argv+argc) {}
    
    const char* getCmdOption(const std::string & option, const char * def = 0);
    bool cmdOptionExists(const std::string& option);
  
  private:
    char ** m_begin;
    char ** m_end;
  };


}

#endif
