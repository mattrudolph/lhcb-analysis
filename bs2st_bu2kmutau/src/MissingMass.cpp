

#include "MissingMass.h"
#include "Particles.h"
#include "bs2st2buk_kmux_vars.h"
#include "Utils.h"
#include <cmath>
#include <iostream>

namespace bs2st_bu2kmutau {
  
  ///Calculate missing mass from B+ decay for B_s2^* -> B+ K-
  //Takes two daughters for now...
  //stable Daughters don't have to be a derived class since only using their four-momentum
  ///Returns MissingEnergy1, MM1, MissingEnergy2, MM2 in vector
  std::vector<double> missingMassSq( const AnalysisBase::InterParticle & bu, const AnalysisBase::Particle & km, const AnalysisBase::Particle & d1, const AnalysisBase::Particle & d2 ) {

    std::vector<double> ret;

    //use hardcoded numbers for now
    const double mbs2st = 5839.83; //MeV +- 0.19
    const double mbu = 5279.29; //+-0.15
    const double mk  = 493.677; //+-0.016
    
    ////
    //First need to calculate the B momentum
    ////

    double delta = mbs2st*mbs2st - mbu*mbu - mk*mk;

    double bdx = (bu.ENDVERTEX_X - bu.OWNPV_X);
    double bdy = (bu.ENDVERTEX_Y - bu.OWNPV_Y);
    double bdz = (bu.ENDVERTEX_Z - bu.OWNPV_Z);
    double l2 = bdx*bdx + bdy*bdy + bdz*bdz;

    //cos^2 angle between b and k in lab, multiplied by magnitude of kaon momentum^2
    //square the dot product of k mom and b path, divide by length of b decay path squared
    double pk2cos2theta = (( bdx*km.PX + bdy*km.PY + bdz*km.PZ )*( bdx*km.PX + bdy*km.PY + bdz*km.PZ )) / l2;

    //setup quadratic formula
    double a = (4*km.PE*km.PE - 4*pk2cos2theta );
    double b = -4*km.PE*delta;
    double c = delta*delta + 4*mbu*mbu*pk2cos2theta;

    double disc = 1 - 4*a*c/(b*b);

    if( disc < 0) {
      //std::cout << "disc = " << disc << std::endl;
      return ret;
    }

    double sol1 = b*(-1 + std::sqrt( disc ))/(2*a);
    double sol2 = b*(-1 - std::sqrt( disc ))/(2*a);


    //solve for energy of missing particle
    double de1 = sol1 - d1.PE - d2.PE;
    double de2 = sol2 - d1.PE - d2.PE;

    //solve for its momentum components
    double bp1 = std::sqrt(sol1*sol1 - mbu*mbu);
    double bp2 = std::sqrt(sol2*sol2 - mbu*mbu);
    double l = std::sqrt(l2);

    double dpx1 = ( bp1*bdx/l ) - d1.PX - d2.PX;
    double dpy1 = ( bp1*bdy/l ) - d1.PY - d2.PY;
    double dpz1 = ( bp1*bdz/l ) - d1.PZ - d2.PZ;

    double dpx2 = ( bp2*bdx/l ) - d1.PX - d2.PX;
    double dpy2 = ( bp2*bdy/l ) - d1.PY - d2.PY;
    double dpz2 = ( bp2*bdz/l ) - d1.PZ - d2.PZ;

    //Solve for the missing mass^2
    double mm1 = de1*de1 - dpx1*dpx1 - dpy1*dpy1 - dpz1*dpz1;
    double mm2 = de2*de2 - dpx2*dpx2 - dpy2*dpy2 - dpz2*dpz2;

    //return in GeV
    ret.push_back(de1/1000.);
    ret.push_back(mm1/1000000.);
    ret.push_back(de2/1000.);
    ret.push_back(mm2/1000000.);
    return ret;
  }

}
