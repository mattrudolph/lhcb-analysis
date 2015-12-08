from Gaudi.Configuration import *

from Configurables import DaVinci,GaudiSequencer

DaVinci().DataType = "2012"
DaVinci().EvtMax = -1
DaVinci().TupleFile = "bs2st2buk_rhomunu.root"

from bs2st_bu2rhomunu.options.rhomuselection import *
seqBss2buk = makeSelectionSequence( "B2XuMuNuBu2RhoLine", "Semileptonic" )
seqBss2bukSS = makeSelectionSequenceSS( "B2XuMuNuBu2RhoLine", "Semileptonic" )

seqRhoSB = makeSelectionSequence("B2XuMuNuBu2RhoSBLine", "Semileptonic" )
seqRhoWS = makeSelectionSequence("B2XuMuNuBu2RhoWSLine", "Semileptonic" )

from bs2st_bu2rhomunu.options.rhomutuples import *

tuple = makeTuple( "Bs2st2BuK_RhoMuX_Tuple" )
tupleSS = makeTupleSS( "Bs2st2BuKSS_RhoMuX_Tuple" )

tupleSB = makeTuple( "Bs2st2BuK_RhoSBMuX_Tuple" )
tupleWS = makeTupleRhoWS( "Bs2st2BuK_RhoWSMuX_Tuple" )

tuple.Inputs = [ seqBss2buk.outputLocation() ]
tupleSS.Inputs = [ seqBss2bukSS.outputLocation() ]
tupleSB.Inputs = [ seqRhoSB.outputLocation() ]
tupleWS.Inputs = [ seqRhoWS.outputLocation() ]


SequenceOS = GaudiSequencer('SequenceOS')
SequenceSS = GaudiSequencer('SequenceSS')
SequenceSB = GaudiSequencer('SequenceSB')
SequenceWS = GaudiSequencer('SequenceWS')

SequenceOS.Members = [ seqBss2buk.sequence(), tuple ]
SequenceSS.Members = [ seqBss2bukSS.sequence(), tupleSS ]
SequenceSB.Members = [ seqRhoSB.sequence(), tupleSB ]
SequenceWS.Members = [ seqRhoWS.sequence(), tupleWS ]

DaVinci().UserAlgorithms = [ SequenceOS, SequenceSS, SequenceSB, SequenceWS ]
