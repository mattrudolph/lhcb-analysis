
def addBs2stInfo(branch):
    tool = branch.addTupleTool("LoKi::Hybrid::TupleTool/Loki_bs2st")
    tool.Variables = {
        "PID": "ID",
        "M": "M",
        "MM":"MM",
        "P":"P",
        "PT":"PT",
        "PHI":"PHI",
        "ETA":"ETA",
        "BPVDIRA":"BPVDIRA",
        "BPVIPCHI2":"BPVIPCHI2()",
        "VCHI2PDOF":"VFASPF(VCHI2PDOF)",
        "MIPCHI2DV":"MIPCHI2DV(PRIMARY)"}

def addKaonInfo(branch):
    tool = branch.addTupleTool("LoKi::Hybrid::TupleTool/Loki_k")
    tool.Variables = {
        "PID": "ID",
        "M": "M",
        "MM":"MM",
        "P":"P",
        "PT":"PT",
        "PHI":"PHI",
        "ETA":"ETA",
        "TRCHI2DOF":"TRCHI2DOF",
        "TRGHOSTPROB":"TRGHOSTPROB",
        "MIPCHI2DV":"MIPCHI2DV(PRIMARY)",
        "BPVIPCHI2":"BPVIPCHI2()",
        "PIDK":"PIDK",
        "PIDp":"PIDp",
        "PIDmu":"PIDmu",
        "BPVZ":"BPV(VZ)"}

def addBuInfo(branch):
    tool = branch.addTupleTool("LoKi::Hybrid::TupleTool/Loki_bu")
    tool.Variables = {
        "PID": "ID",
        "M": "M",
        "MM":"MM",
        "P":"P",
        "PT":"PT",
        "PHI":"PHI",
        "ETA":"ETA",
        "MIPCHI2DV":"MIPCHI2DV(PRIMARY)",
        "BPVIPCHI2":"BPVIPCHI2()",
        "BPVVDCHI2":"BPVVDCHI2",
        "BPVDIRA":"BPVDIRA",
        "BPVLTIME":"BPVLTIME()",
        "BPVZ":"BPV(VZ)",
        "VCHI2PDOF":"VFASPF(VCHI2PDOF)"}

def addJpsiInfo(branch):
    tool = branch.addTupleTool("LoKi::Hybrid::TupleTool/Loki_j")
    tool.Variables = {
        "PID": "ID",
        "M": "M",
        "MM":"MM",
        "P":"P",
        "PT":"PT",
        "PHI":"PHI",
        "ETA":"ETA",
        "VCHI2PDOF":"VFASPF(VCHI2PDOF)"}


def addMuonInfo(branch):
    tool = branch.addTupleTool("LoKi::Hybrid::TupleTool/Loki_mu")
    tool.Variables = {
        "PID": "ID",
        "M": "M",
        "MM":"MM",
        "P":"P",
        "PT":"PT",
        "PHI":"PHI",
        "ETA":"ETA",
        "TRCHI2DOF":"TRCHI2DOF",
        "TRGHOSTPROB":"TRGHOSTPROB",
        "MIPCHI2DV":"MIPCHI2DV(PRIMARY)",
        "PIDK":"PIDK",
        "PIDp":"PIDp",
        "PIDmu":"PIDmu",
        "BPVZ":"BPV(VZ)"}
    
