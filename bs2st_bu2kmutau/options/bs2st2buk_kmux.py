from Gaudi.Configuration import *

from Configurables import DaVinci,GaudiSequencer

DaVinci().DataType = "2012"
DaVinci().EvtMax = -1
DaVinci().TupleFile = "bs2st2buk_kmux.root"

from bs2st_bu2kmutau.options.kmuxselection import *
from bs2st_bu2kmutau.options.kmuxtuples import *

tuple.Inputs = [ seqBss2buk.outputLocation() ]
tupleSS.Inputs = [ seqBss2bukSS.outputLocation() ]

SequenceOS = GaudiSequencer('SequenceOS')
SequenceSS = GaudiSequencer('SequenceSS')

SequenceOS.Members = [ seqBss2buk.sequence(), tuple ]
SequenceSS.Members = [ seqBss2bukSS.sequence(), tupleSS ]


DaVinci().UserAlgorithms = [ SequenceOS, SequenceSS ]
