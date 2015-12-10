"""
Provides selections for B*_s20 -> (B+ -> J/psi K+) K- staring from (B+ -> J/psi K+) stripping.

"""

line = "BetaSBu2JpsiKDetachedLine"
#location = "/Event/AllStreams/Phys/"+line+"/Particles"
location = "/Event/Dimuon/Phys/"+line+"/Particles"

from Configurables import LoKi__HDRFilter,FilterDesktop
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence

strippingfilter = LoKi__HDRFilter( 'StripPassFilter', Code="HLT_PASS('Stripping"+line+"Decision')", Location="/Event/Strip/Phys/DecReports")

BuSel = AutomaticData(Location = location)

_buFilter = FilterDesktop('buFilter', Code = "(BPVDIRA > 0.98) & (BPVVDCHI2 > 100.0) & (VFASPF(VCHI2PDOF) < 5) & (INTREE( (ABSID=='K+') & (PIDK > 5) ) )")

BuFilterSel = Selection( name = 'BuFilterSel', Algorithm = _buFilter, RequiredSelections = [ BuSel ] )

from Configurables import CombineParticles
_bss2buk = CombineParticles("Bss2BuK",
                            DecayDescriptor = "[B*_s20 -> B+ K-]CC" ,
                            DaughtersCuts = {'K-': 'PIDK > 5'},
                            CombinationCut = "ADAMASS('B*_s20')<1*GeV",
                            MotherCut = "(VFASPF(VCHI2/VDOF)<10) & (BPVIPCHI2()<20)" )


from StandardParticles import StdAllLooseKaons
Bss2buk = Selection("SelBss2BuK",
                    Algorithm = _bss2buk,
                    RequiredSelections = [ BuFilterSel, StdAllLooseKaons ] )
SeqBss2BuK = SelectionSequence('SeqBss2BuK', TopSelection = Bss2buk )


#Same sign backgrounds
_bss2bukss = CombineParticles("Bss2BuKSS",
                              DecayDescriptor = "[B*_s20 -> B+ K+]CC" ,
                              DaughtersCuts = {'K+': 'PIDK > 5'},
                              CombinationCut = "ADAMASS('B*_s20')<1*GeV",
                              MotherCut = "(VFASPF(VCHI2/VDOF)<10) & (BPVIPCHI2()<20)" )

Bss2bukSS = Selection("SelBss2BuKSS",
                    Algorithm = _bss2bukss,
                    RequiredSelections = [ BuFilterSel, StdAllLooseKaons ] )
SeqBss2BuKSS = SelectionSequence('SeqBss2BuKSS', TopSelection = Bss2bukSS )


