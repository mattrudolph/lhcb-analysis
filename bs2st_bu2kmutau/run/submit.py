"""
Submit bs2st2buk_kmux options 

"""

class SubmitKmux(Submitter):
    def __init__(self):
        Submitter.__init__(self)
        
        #Modify to determine what to run on; label of dataset in box and isMC flag
        self.dataToRun = [("Bs2st->(Bu->Kmutau)K",True),]

        #base options to run
        self.options = "../options/bs2st2buk_kmux.py"

        #output ntuple file
        self.outputs = ["bs2st2buk_kmux.root",]
        
    #Small set so lets change the splitting
    def modJob(self,j):
        j.splitter.filesPerJob=5


        
s = SubmitKmux()
s.submit()
