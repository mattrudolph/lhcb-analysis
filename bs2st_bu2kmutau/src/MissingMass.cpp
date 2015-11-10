

#include "MissingMass.h"
#include "Particles.h"
#include "bs2st2buk_kmux_vars.h"
#include "Utils.h"
#include <cmath>
#include <iostream>

#include "TVector3.h"

namespace bs2st_bu2kmutau {

///Calculate missing mass from B+ decay for B_s2^* -> B+ K-
///Returns Eb1, Eb2, MM1, MM2 in vector
  std::vector<double> missingMassSq( const AnalysisBase::MotherParticle & bs2st, const AnalysisBase::InterParticle & bu, const AnalysisBase::StableParticle & km, const AnalysisBase::StableParticle & mu, const AnalysisBase::StableParticle & kp ) {

    std::vector<double> ret;

    //use hardcoded numbers for now
    const double mbs2st = 5839.83; //MeV +- 0.19
    const double mbu = 5279.29; //+-0.15
    const double mk  = 493.677; //+-0.016
    const double mmu = 105.658;
    
    ////
    //First need to calculate the B momentum
    ////

    double delta = mbs2st*mbs2st - mbu*mbu - mk*mk;

    // std::cout << bs2st.ENDVERTEX_X - bu.OWNPV_X  << ", " <<  bs2st.ENDVERTEX_Y - bu.OWNPV_Y  << ", " <<  bs2st.ENDVERTEX_Z - bu.OWNPV_Z << ", " << std::endl;

    double bdx = (bu.ENDVERTEX_X - bu.OWNPV_X);
    double bdy = (bu.ENDVERTEX_Y - bu.OWNPV_Y);
    double bdz = (bu.ENDVERTEX_Z - bu.OWNPV_Z);

    std::cout << bdx << ", " << bdy << ", " << bdz << std::endl;
    double l2 = bdx*bdx + bdy*bdy + bdz*bdz;

    TVector3 vb( bdx/std::sqrt(l2), bdy/std::sqrt(l2), bdz/std::sqrt(l2) );
    TVector3 vk( km.PX/km.P, km.PY/km.P, km.PZ/km.P);

    double costheta = vb.Dot(vk);
    double pk2 = km.P*km.P;

    //    std::cout << "costheta = " << costheta << ", pk2 = " << pk2 << std::endl;

    //cos^2 angle between b and k in lab, multiplied by magnitude of kaon momentum^2
    //square the dot product of k mom and b path, divide by length of b decay path squared
    double pk2cos2theta = (( bdx*km.PX + bdy*km.PY + bdz*km.PZ )*( bdx*km.PX + bdy*km.PY + bdz*km.PZ )) / l2;

    //    std::cout << "delta = " << delta << ", pk2cos2theta = " << pk2cos2theta << std::endl;

    //setup quadratic formula
    double a = (4*km.PE*km.PE - 4*pk2cos2theta );
    double b = -4*km.PE*delta;
    double c = delta*delta + 4*mbu*mbu*pk2cos2theta;

    // std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
    // std::cout << "a = " << 4*(mk*mk + pk2*( 1 - costheta )*(1+costheta) ) << std::endl;
    double disc = b*b - 4*a*c;

    double rb = mbu/mbs2st;
    double rk = mk/mbs2st;
    double factor = ( 1 + rb*rb*rb*rb + rk*rk*rk*rk ) - 2*( rb*rb + rb*rb*rk*rk + rk*rk );
    double altdisc = 1 - 4*a*c/(b*b);

      // 16*pk2cos2theta *( factor + 4*mbu*mbu*pk2*(costheta + 1 )*(costheta-1)/(mbs2st*mbs2st*mbs2st*mbs2st) );

    double discsign = ( km.PE*km.PE - pk2cos2theta );
    // std::cout << "discsign = " << discsign << std::endl;
    // std::cout << "factor = " << factor << ", altdisc = " << altdisc << std::endl;

    disc = altdisc;

    if( disc < 0) {
      std::cout << "disc = " << disc << std::endl;
      return ret;
    }

    double sol1 = (-b + std::sqrt( b*b - 4*a*c ))/(2*a);
    double sol2 = (-b - std::sqrt( b*b - 4*a*c ))/(2*a);

    ret.push_back(sol1/1000.);
    ret.push_back(sol2/1000.);

    double de1 = sol1 - mu.PE - kp.PE;
    double de2 = sol2 - mu.PE - kp.PE;

    double bp1 = std::sqrt(sol1*sol1 - mbu*mbu);
    double bp2 = std::sqrt(sol2*sol2 - mbu*mbu);
    double l = std::sqrt(l2);

    double dpx1 = ( bp1*bdx/l ) - mu.PX - kp.PX;
    double dpy1 = ( bp1*bdy/l ) - mu.PY - kp.PY;
    double dpz1 = ( bp1*bdz/l ) - mu.PZ - kp.PZ;

    double dpx2 = ( bp2*bdx/l ) - mu.PX - kp.PX;
    double dpy2 = ( bp2*bdy/l ) - mu.PY - kp.PY;
    double dpz2 = ( bp2*bdz/l ) - mu.PZ - kp.PZ;

    double mm1 = de1*de1 - dpx1*dpx1 - dpy1*dpy1 - dpz1*dpz1;
    double mm2 = de2*de2 - dpx2*dpx2 - dpy2*dpy2 - dpz2*dpz2;

    ret.push_back(mm1/1000000.);
    ret.push_back(mm2/1000000.);
    return ret;
  }

}
