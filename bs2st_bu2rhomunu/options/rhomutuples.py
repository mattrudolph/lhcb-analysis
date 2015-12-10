from bs2st_bu2rhomunu.options.tuplebranchinfos import *

from DecayTreeTuple.Configuration import *


toolList = ['TupleToolGeometry',
            'TupleToolPrimaries',
            'TupleToolEventInfo',
            'TupleToolAngles',]

def makeTuple(name):
    tuple = DecayTreeTuple(name)
    tuple.Decay = "[B*_s20 -> ^(B+ -> ^(rho(770)0 -> ^pi+ ^pi-) ^mu+) ^K-]CC"

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

    return tuple

def makeTupleSS(name):
    tupleSS = DecayTreeTuple(name)
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

    return tupleSS

def makeTupleRhoWS(name):
    tuple = DecayTreeTuple(name)
    tuple.Decay = "([B*_s20 -> ^(B+ -> ^(rho(770)0 -> ^pi+ ^pi+) ^mu+) ^K-]CC) || ([B*_s20 -> ^(B+ -> ^(rho(770)0 -> ^pi- ^pi-) ^mu+) ^K-]CC)"

    tuple.ToolList += toolList

    tuple.addBranches({
        "Bs2st" : "^(([B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi+) mu+) K-]CC) || ([B*_s20 -> (B+ -> (rho(770)0 -> pi- pi-) mu+) K-]CC))",
        "Bu"    : "([B*_s20 -> ^(B+ -> (rho(770)0 -> pi+ pi+) mu+) K-]CC) || ([B*_s20 -> ^(B+ -> (rho(770)0 -> pi- pi-) mu+) K-]CC)",
        "Km"    : "([B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi+) mu+) ^K-]CC) || ([B*_s20 -> (B+ -> (rho(770)0 -> pi- pi-) mu+) ^K-]CC)",
        "Rho"   : "([B*_s20 -> (B+ -> ^(rho(770)0 -> pi+ pi+) mu+) K-]CC) || ([B*_s20 -> (B+ -> ^(rho(770)0 -> pi- pi-) mu+) K-]CC)",
        "Pip"   : "([B*_s20 -> (B+ -> (rho(770)0 -> ^pi+ pi+) mu+) K-]CC) || ([B*_s20 -> (B+ -> (rho(770)0 -> ^pi- pi-) mu+) K-]CC)",
        "Pim"   : "([B*_s20 -> (B+ -> (rho(770)0 -> pi+ ^pi+) mu+) K-]CC) || ([B*_s20 -> (B+ -> (rho(770)0 -> pi- ^pi-) mu+) K-]CC)",
        "Mu"    : "([B*_s20 -> (B+ -> (rho(770)0 -> pi+ pi+) ^mu+) K-]CC) || ([B*_s20 -> (B+ -> (rho(770)0 -> pi- pi-) ^mu+) K-]CC)",
    })

    addBs2stInfo(tuple.Bs2st)
    addBuInfo(tuple.Bu)
    addKaonInfo(tuple.Km)
    addRhoInfo(tuple.Rho)
    addPionInfo(tuple.Pip)
    addPionInfo(tuple.Pim)
    addMuonInfo(tuple.Mu)

    return tuple


def makeTupleNoBs2st(name):
    tuple=DecayTreeTuple(name)
    tuple.Decay = "[B+ -> ^(rho(770)0 -> ^pi+ ^pi-) ^mu+]CC"
    tuple.ToolList += toolList

    tuple.addBranches({
        "Bu"  : "^([B+ -> (rho(770)0 -> pi+ pi-) mu+]CC)",
        "Rho" : "[B+ -> ^(rho(770)0 -> pi+ pi-) mu+]CC",
        "Pip" : "[B+ -> (rho(770)0 -> ^pi+ pi-) mu+]CC",
        "Pim" : "[B+ -> (rho(770)0 -> pi+ ^pi-) mu+]CC",
        "Mu"  : "[B+ -> (rho(770)0 -> pi+ pi-) ^mu+]CC",
    })
    
    addBuInfo(tuple.Bu)
    addRhoInfo(tuple.Rho)
    addPionInfo(tuple.Pip)
    addPionInfo(tuple.Pim)
    addMuonInfo(tuple.Mu)

    return tuple
