from bs2st_bu2kmutau.options.tuplebranchinfos import *

from DecayTreeTuple.Configuration import *
from Configurables import TupleToolTISTOS

tuple = DecayTreeTuple("Bs2st2BuK_JpsiK_Tuple")
tuple.Decay = "[B*_s20 -> ^(B+ -> ^(J/psi(1S) -> ^mu+ ^mu-) ^K+) ^K-]CC"

toolList = ['TupleToolGeometry',
            'TupleToolPrimaries',
            'TupleToolEventInfo',
            'TupleToolAngles',]
tuple.ToolList += toolList

tuple.addBranches({
    "Bs2st" : "^([B*_s20 -> (B+ -> (J/psi(1S) -> mu+ mu-) K+) K-]CC)",
    "Bu"    : "[B*_s20 -> ^(B+ -> (J/psi(1S) -> mu+ mu-) K+) K-]CC",
    "Km"    : "[B*_s20 -> (B+ -> (J/psi(1S) -> mu+ mu-) K+) ^K-]CC",
    "Jpsi"  : "[B*_s20 -> (B+ -> ^(J/psi(1S) -> mu+ mu-) K+) K-]CC",
    "Kp"    : "[B*_s20 -> (B+ -> (J/psi(1S) -> mu+ mu-) ^K+) K-]CC",
    "Mup"   : "[B*_s20 -> (B+ -> (J/psi(1S) -> ^mu+ mu-) K+) K-]CC",
    "Mum"   : "[B*_s20 -> (B+ -> (J/psi(1S) -> mu+ ^mu-) K+) K-]CC"}
)

addBs2stInfo(tuple.Bs2st)
addBuInfo(tuple.Bu)
addKaonInfo(tuple.Km)
addJpsiInfo(tuple.Jpsi)
addKaonInfo(tuple.Kp)
addMuonInfo(tuple.Mup)
addMuonInfo(tuple.Mum)

tuple.addTool(TupleToolTISTOS)
tuple.TupleToolTISTOS.TriggerList = ["Hlt2DiMuonJPsiDecision" ]
tuple.TupleToolTISTOS.VerboseHlt2 = True


tupleSS = DecayTreeTuple("Bss2BuKSS_JpsiK_Tuple")
tupleSS.Decay = "[B*_s20 -> ^(B+ -> ^(J/psi(1S) -> ^mu+ ^mu-) ^K+) ^K+]CC"

tupleSS.ToolList += toolList

tupleSS.addBranches({
    "Bs2st" : "^([B*_s20 -> (B+ -> (J/psi(1S) -> mu+ mu-) K+) K+]CC)",
    "Bu"    : "[B*_s20 -> ^(B+ -> (J/psi(1S) -> mu+ mu-) K+) K+]CC",
    "K1"    : "[B*_s20 -> (B+ -> (J/psi(1S) -> mu+ mu-) K+) ^K+]CC",
    "Jpsi"  : "[B*_s20 -> (B+ -> ^(J/psi(1S) -> mu+ mu-) K+) K+]CC",
    "K2"    : "[B*_s20 -> (B+ -> (J/psi(1S) -> mu+ mu-) ^K+) K+]CC",
    "Mup"   : "[B*_s20 -> (B+ -> (J/psi(1S) -> ^mu+ mu-) K+) K+]CC",
    "Mum"   : "[B*_s20 -> (B+ -> (J/psi(1S) -> mu+ ^mu-) K+) K+]CC"}
)

addBs2stInfo(tupleSS.Bs2st)
addBuInfo(tupleSS.Bu)
addKaonInfo(tupleSS.K1)
addJpsiInfo(tupleSS.Jpsi)
addKaonInfo(tupleSS.K2)
addMuonInfo(tupleSS.Mup)
addMuonInfo(tupleSS.Mum)

tupleSS.addTool(TupleToolTISTOS)
tupleSS.TupleToolTISTOS.TriggerList = ["Hlt2DiMuonJPsiDecision" ]
tupleSS.TupleToolTISTOS.VerboseHlt2 = True
