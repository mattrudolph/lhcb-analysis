"""
Submit bs2st2buk_kmux options 

"""

class SubmitMC(Submitter):
    def __init__(self):
        Submitter.__init__(self)
        
    #Small set so lets change the splitting
    def modJob(self,j):
        j.splitter.filesPerJob=5



        
kmux = SubmitMC()

#Modify to determine what to run on; label of dataset in box and isMC flag
kmux.dataToRun = [("Bs2st->(Bu->Kmutau)K",True),
                  ]

#base options to run
kmux.options = "../options/bs2st2buk_kmux.py"

#output ntuple file
kmux.outputs = ["bs2st2buk_kmux.root",]

kmux.submit()


jpsik = SubmitMC()

#Modify to determine what to run on; label of dataset in box and isMC flag
jpsik.dataToRun = [
                   ("Bs2st->(Bu->KJpsi)K",True),
                   ]

jpsik.options = "../options/bs2st2buk_jpsi.py"
jpsik.outputs = ["bs2st2buk_jpsik.root"]

jpsik.submit()
