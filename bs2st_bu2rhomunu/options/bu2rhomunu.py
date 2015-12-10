from Gaudi.Configuration import *

from Configurables import DaVinci,GaudiSequencer

DaVinci().DataType = "2012"
DaVinci().EvtMax = -1
DaVinci().TupleFile = "bu2rhomunu.root"

#from bs2st_bu2rhomunu.options.rhomuselection import *
#seq = makeSelectionSequenceNoBs2st("B2XuMuNuBu2RhoLine", "Semileptonic" )

line = "B2XuMuNuBu2RhoLine"
stream = "AllStreams"

#def makeSelectionSequenceNoBs2st( line, stream):
location = "/Event/" + stream + "/Phys/" + line + "/Particles"
from Configurables import LoKi__HDRFilter
strippingfilter = LoKi__HDRFilter( 'StripPassFilter', Code="HLT_PASS('Stripping"+line+"Decision')", Location="/Event/Strip/Phys/DecReports")

# AutomaticData(Location = location)

from bs2st_bu2rhomunu.options.rhomutuples import *

tuple = makeTupleNoBs2st( "Bu2RhoMuX_Tuple" )

#print seq.outputLocation()

#tuple.Inputs = [ seq.outputLocation() ]

tuple.Inputs = [ location ]

Sequence = GaudiSequencer('Sequence')

Sequence.Members = [ strippingfilter, tuple ]

DaVinci().UserAlgorithms = [ Sequence ]
