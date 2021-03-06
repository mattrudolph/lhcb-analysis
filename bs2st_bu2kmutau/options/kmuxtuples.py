from bs2st_bu2kmutau.options.tuplebranchinfos import *

from DecayTreeTuple.Configuration import *


tuple = DecayTreeTuple("Bs2st2BuK_KMuX_Tuple")
tuple.Decay = "([B*_s20 -> ^(B+ -> ^mu+ ^K+) ^K-]CC) || ([B*_s20 -> ^(B+ -> ^mu- ^K+) ^K-]CC)"

toolList = ['TupleToolGeometry',
            'TupleToolPrimaries',
            'TupleToolEventInfo',
            'TupleToolTISTOS',
            'TupleToolAngles',]
tuple.ToolList += toolList

tuple.addBranches({
    "Bs2st" : "^(([B*_s20 -> (B+ -> mu+ K+) K-]CC) || ([B*_s20 -> (B+ -> mu- K+) K-]CC))",
    "Bu"    : "([B*_s20 -> ^(B+ -> mu+ K+) K-]CC) || ([B*_s20 -> ^(B+ -> mu- K+) K-]CC)",
    "Km"    : "([B*_s20 -> (B+ -> mu+ K+) ^K-]CC) || ([B*_s20 -> (B+ -> mu- K+) ^K-]CC)",
    "Kp"    : "([B*_s20 -> (B+ -> mu+ ^K+) K-]CC) || ([B*_s20 -> (B+ -> mu- ^K+) K-]CC)",
    "Mu"    : "([B*_s20 -> (B+ -> ^mu+ K+) K-]CC) || ([B*_s20 -> (B+ -> ^mu- K+) K-]CC)",
})



addBs2stInfo(tuple.Bs2st)
addBuInfo(tuple.Bu)
addKaonInfo(tuple.Km)
addKaonInfo(tuple.Kp)
addMuonInfo(tuple.Mu)




tupleSS = DecayTreeTuple("Bs2st2BuKSS_KMuX_Tuple")
tupleSS.Decay = "([B*_s20 -> ^(B+ -> ^mu+ ^K+) ^K+]CC) || ([B*_s20 -> ^(B+ -> ^mu- ^K+) ^K+]CC)"
tupleSS.ToolList += toolList

#The "Km" is of course really the K+ attached at top level -- but this give same tree structure as right sign
tupleSS.addBranches({
    "Bs2st" : "^(([B*_s20 -> (B+ -> mu+ K+) K+]CC) || ([B*_s20 -> (B+ -> mu- K+) K+]CC))",
    "Bu"    : "([B*_s20 -> ^(B+ -> mu+ K+) K+]CC) || ([B*_s20 -> ^(B+ -> mu- K+) K+]CC)",
    "Km"    : "([B*_s20 -> (B+ -> mu+ K+) ^K+]CC) || ([B*_s20 -> (B+ -> mu- K+) ^K+]CC)",
    "Kp"    : "([B*_s20 -> (B+ -> mu+ ^K+) K+]CC) || ([B*_s20 -> (B+ -> mu- ^K+) K+]CC)",
    "Mu"    : "([B*_s20 -> (B+ -> ^mu+ K+) K+]CC) || ([B*_s20 -> (B+ -> ^mu- K+) K+]CC)",
})



addBs2stInfo(tupleSS.Bs2st)
addBuInfo(tupleSS.Bu)
addKaonInfo(tupleSS.Km)
addKaonInfo(tupleSS.Kp)
addMuonInfo(tupleSS.Mu)
