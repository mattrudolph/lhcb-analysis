"""
Provides selections for B*_s20 -> B+ K- and same sign combinatorics

"""


from Configurables import FilterDesktop,CombineParticles
from StandardParticles import StdAllLooseKaons,StdLooseKaons,StdLooseMuons
from PhysSelPython.Wrappers import Selection, SelectionSequence

#Muons we want to use
mu = FilterDesktop('mu',
                      Code = "(TRCHI2DOF < 3) & (TRGHOSTPROB < 0.5) & (P > 3000.0 *MeV) & (PT > 1000.0 *MeV) & (MIPCHI2DV(PRIMARY) > 9.0) & (PIDmu-PIDK > 0) & (PIDmu-PIDp > 0) & (PIDmu-PIDpi > 0.0)")

selMu = Selection('selMu', Algorithm = mu, RequiredSelections = [StdLooseMuons])


#Make B+ to kmuX
bu2kmu = CombineParticles('bu2kmu',
                          DecayDescriptors = ["[B+ -> K+ mu+]cc", "[B+ -> K+ mu-]cc"],
                          CombinationCut = "(AM > 1000.0*MeV) & (AM < 5500.0*MeV)",
                          MotherCut = "(VFASPF(VCHI2/VDOF) < 4.0) & (BPVDIRA > 0.99) & (BPVVDCHI2 > 100.)")

selBu2kmu = Selection('selBu2kmu',
                      Algorithm = bu2kmu,
                      RequiredSelections = [StdLooseKaons, selMu] )

#Kaons for the prompt one
k = FilterDesktop('k',
                     Code = "(TRCHI2DOF < 3) & (TRGHOSTPROB < 0.5) & (PT > 500.0 *MeV) &(MIPCHI2DV(PRIMARY) < 9.0) & (PIDK-PIDpi > 16.0) & (PIDK-PIDp > 0) & (PIDK-PIDmu > 0)" )

selK = Selection('selK', Algorithm = k, RequiredSelections = [StdAllLooseKaons])

#Opposite sign combinations
bss2buk = CombineParticles('bss2buk',
                           DecayDescriptor = "[B*_s20 -> B+ K-]cc",
                           CombinationCut = "(AM-AM1 < 713.677*MeV) & (abs(ACHILD(BPV(VZ),1)-ACHILD(BPV(VZ),2))<1.0*mm)",
                           MotherCut = "(PT > 50.0*MeV)")

selBss2buk = Selection("selBss2buk",
                       Algorithm = bss2buk,
                       RequiredSelections = [selBu2kmu, selK])
seqBss2buk = SelectionSequence('seqBss2buk', TopSelection = selBss2buk)


# Same sign combinations
bss2bukSS = CombineParticles('bss2bukSS',
                             DecayDescriptor = "[B*_s20 -> B+ K+]cc",
                             CombinationCut = "(AM-AM1 < 713.677*MeV) & (abs(ACHILD(BPV(VZ),1)-ACHILD(BPV(VZ),2))<1.0*mm)",
                             MotherCut = "(PT > 50.0*MeV)")

selBss2bukSS = Selection("selBss2bukSS",
                         Algorithm = bss2bukSS,
                         RequiredSelections = [selBu2kmu, selK])
seqBss2bukSS = SelectionSequence('seqBss2bukSS', TopSelection = selBss2bukSS)


