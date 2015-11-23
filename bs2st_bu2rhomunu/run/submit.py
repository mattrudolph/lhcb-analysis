"""
Submit bs2st2buk_rhomunu options 

"""

class Submit(Submitter):
    def __init__(self):
        Submitter.__init__(self)
        
    #Small set so lets change the splitting
    def modJob(self,j):
        j.splitter.filesPerJob=20



        
kmux = Submit()

#Modify to determine what to run on; label of dataset in box and isMC flag
kmux.dataToRun = [("SEMILEPTONIC.DST 2012 strip 21 MagUp",False),
                  ("SEMILEPTONIC.DST 2012 strip 21 MagDown",False),
                  ]

#base options to run
kmux.options = "../options/bs2st2buk_rhomunu.py"

#output ntuple file
kmux.outputs = ["bs2st2buk_rhomunu.root",]

kmux.submit()

