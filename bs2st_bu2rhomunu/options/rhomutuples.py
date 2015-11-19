from bs2st_bu2rhomunu.options.tuplebranchinfos import *

from DecayTreeTuple.Configuration import *

tuple = DecayTreeTuple("Bs2st2BuK_RhoMuX_Tuple")
tuple.Decay = "[B*_s20 -> ^(B+ -> ^(rho(770)0 -> ^pi+ ^pi-) ^mu+) ^K-]CC"
#tuple.Inputs = [ seqBss2BuK.outputLocation() ]

toolList = ['TupleToolGeometry',
            'TupleToolPrimaries',
            'TupleToolEventInfo',
            'TupleToolAngles',]
tuple.ToolList += toolList

tuple.addBranches({
    "Bs2st" : "^([B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi-) mu+) K-]CC)",
    "Bu"    : "[B*_s20 -> ^(B+ -> (rho(770)0 -> pi+ pi-) mu+) K-]CC",
    "Km"    : "[B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi-) mu+) ^K-]CC",
    "Rho"   : "[B*_s20 -> (B+ -> ^(rho(770)0 -> pi+ pi-) mu+) K-]CC",
    "Pip"   : "[B*_s20 -> (B+ -> (rho(770)0 -> ^pi+ pi-) mu+) K-]CC",
    "Pim"   : "[B*_s20 -> (B+ -> (rho(770)0 -> pi+ ^pi-) mu+) K-]CC",
    "Mu"    : "[B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi-) ^mu+) K-]CC",
})


addBs2stInfo(tuple.Bs2st)
addBuInfo(tuple.Bu)
addKaonInfo(tuple.Km)
addRhoInfo(tuple.Rho)
addPionInfo(tuple.Pip)
addPionInfo(tuple.Pim)
addMuonInfo(tuple.Mu)


tupleSS = DecayTreeTuple("Bs2st2BuKSS_RhoMuX_Tuple")
tupleSS.Decay = "[B*_s20 -> ^(B+ -> ^(rho(770)0 -> ^pi+ ^pi-) ^mu+) ^K+]CC"
#tupleSS.Inputs = [ seqBss2BuK.outputLocation() ]

tupleSS.ToolList += toolList

tupleSS.addBranches({
    "Bs2st" : "^([B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi-) mu+) K+]CC)",
    "Bu"    : "[B*_s20 -> ^(B+ -> (rho(770)0 -> pi+ pi-) mu+) K+]CC",
    "Km"    : "[B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi-) mu+) ^K+]CC",
    "Rho"   : "[B*_s20 -> (B+ -> ^(rho(770)0 -> pi+ pi-) mu+) K+]CC",
    "Pip"   : "[B*_s20 -> (B+ -> (rho(770)0 -> ^pi+ pi-) mu+) K+]CC",
    "Pim"   : "[B*_s20 -> (B+ -> (rho(770)0 -> pi+ ^pi-) mu+) K+]CC",
    "Mu"    : "[B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi-) ^mu+) K+]CC",
})


addBs2stInfo(tupleSS.Bs2st)
addBuInfo(tupleSS.Bu)
addKaonInfo(tupleSS.Km)
addRhoInfo(tupleSS.Rho)
addPionInfo(tupleSS.Pip)
addPionInfo(tupleSS.Pim)
addMuonInfo(tupleSS.Mu)

