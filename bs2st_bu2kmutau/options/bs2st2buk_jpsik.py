from Gaudi.Configuration import *

from Configurables import DaVinci,GaudiSequencer

DaVinci().DataType = "2011"
DaVinci().EvtMax = -1
DaVinci().TupleFile = "bs2st2buk_jpsik.root"

from bs2st_bu2kmutau.options.jpsikkselection import *
from bs2st_bu2kmutau.options.jpsikktuples import *

tuple.Inputs = [ SeqBss2BuK.outputLocation() ]
tupleSS.Inputs = [ SeqBss2BuKSS.outputLocation() ]

SequenceOS = GaudiSequencer('SequenceOS')
SequenceSS = GaudiSequencer('SequenceSS')

SequenceOS.Members = [ strippingfilter, SeqBss2BuK.sequence(), tuple ]
SequenceSS.Members = [ strippingfilter, SeqBss2BuKSS.sequence(), tupleSS ]


DaVinci().UserAlgorithms = [ SequenceOS, SequenceSS ]
