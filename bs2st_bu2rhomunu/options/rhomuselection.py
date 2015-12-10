"""
Provides selections for B*s20 -> B+ K- and same sign combinatorics

"""

#line = "B2XuMuNuBu2RhoLine"
#location = "/Event/AllStreams/Phys/"+line+"/Particles"
#location = "/Event/Semileptonic/Phys/"+line+"/Particles"


from Configurables import LoKi__HDRFilter,FilterDesktop,CombineParticles
from StandardParticles import StdAllLooseKaons,StdLooseKaons,StdLooseMuons
from PhysSelPython.Wrappers import AutomaticData, Selection, SelectionSequence


#Kaons for the prompt one
k = FilterDesktop('k',
                     Code = "(TRCHI2DOF < 3) & (TRGHOSTPROB < 0.5) & (PT > 500.0 *MeV) &(MIPCHI2DV(PRIMARY) < 9.0) & (PIDK-PIDpi > 16.0) & (PIDK-PIDp > 0) & (PIDK-PIDmu > 0)" )

selK = Selection('selK', Algorithm = k, RequiredSelections = [StdAllLooseKaons])



bss2buk = CombineParticles("Bss2BuK",
                            DecayDescriptor = "[B*_s20 -> B+ K-]cc" ,
                            CombinationCut = "(AM-AM1 < 713.677*MeV) & (abs(ACHILD(BPV(VZ),1)-ACHILD(BPV(VZ),2))<1.0*mm)",
                            MotherCut = "(PT > 50.0*MeV)")


# Same sign combinations
bss2bukSS = CombineParticles('bss2bukSS',
                             DecayDescriptor = "[B*_s20 -> B+ K+]cc",
                             CombinationCut = "(AM-AM1 < 713.677*MeV) & (abs(ACHILD(BPV(VZ),1)-ACHILD(BPV(VZ),2))<1.0*mm)",
                             MotherCut = "(PT > 50.0*MeV)")


def makeSelectionSequence( line, stream ):

    location = "/Event/" + stream + "/Phys/" + line + "/Particles"
    
    strippingfilter = LoKi__HDRFilter( 'StripPassFilter', Code="HLT_PASS('Stripping"+line+"Decision')", Location="/Event/Strip/Phys/DecReports")

    BuSel = AutomaticData(Location = location)

    selBss2buk = Selection("selBss2buk"+line,
                           Algorithm = bss2buk,
                           RequiredSelections = [BuSel, selK])

    return SelectionSequence('seqBss2buk'+line, TopSelection = selBss2buk)


def makeSelectionSequenceSS( line, stream ):

    location = "/Event/" + stream + "/Phys/" + line + "/Particles"
    
    strippingfilter = LoKi__HDRFilter( 'StripPassFilter', Code="HLT_PASS('Stripping"+line+"Decision')", Location="/Event/Strip/Phys/DecReports")

    BuSel = AutomaticData(Location = location)
    
    selBss2bukSS = Selection("selBss2bukSS"+line,
                             Algorithm = bss2bukSS,
                             RequiredSelections = [BuSel, selK])
    return SelectionSequence('seqBss2bukSS'+line, TopSelection = selBss2bukSS)


