"""
Submit bs2st2buk_rhomunu options 

"""

class Submit(Submitter):
    def __init__(self):
        Submitter.__init__(self)
        
    #Small set so lets change the splitting
    def modJob(self,j):
        j.splitter.filesPerJob=5



        
kmux = Submit()

#Modify to determine what to run on; label of dataset in box and isMC flag
kmux.dataToRun = [#("Bu->rhomunu MagDown",True),
                  ("Bu->rhomunu MagUp",True),
                  ]

#base options to run
kmux.options = "../options/bu2rhomunu.py"

#output ntuple file
kmux.outputs = ["bu2rhomunu.root",]

kmux.submit()

