"""
Helper functions for use inside ganga

"""


import os

###############
#Job management
###############
def createLocalJob(n):
    return Job(name=n,application=DaVinci(),backend=Local())

def createGridJob(n):
    return Job(name=n,application=DaVinci(),backend=Dirac(),splitter=SplitByFiles(filesPerJob=25))

#download output diracfiles for a job if they are done and do not exist yet locally
def getAllCompleted( job ):
    for sj in job.subjobs:
        if sj.status == "completed":
            for f in sj.outputfiles.get(DiracFile):
                if not os.path.exists(sj.outputdir + '/' + f.namePattern):
                    f.localDir = sj.outputdir
                    print "Downloading " + sj.outputdir + '/' + f.namePattern
                    f.get()



###################
#Dataset management
###################


#use bookkeeping query to get a path and return the dataset
def getDataset( bkpath, flag='OK' ):
    return BKQuery( bkpath, dqflag=[flag]).getDataset()

#find data we already put in the box
def findDataInBox(n):
    #would enforce type = LHCbDataset but haven't figured out how yet
    #also would return a list of data matching pattern but can't figure that out either
    slice = box.select(name=n)
    l = len( slice )
    if( l == 1 ):
        return slice[0]
    elif( l > 1 ):
        print "Warning: multiple datasets matching", n, "in box; returning the first"
        return slice[0]
    else:
        return None

#Check if a full bookkeeping path is in the box with the given label, and if not add it
def addFullPathToBox(path,label):
    if (len( box.select( name = label ) ) == 0 ):
        box.add( BKQuery( path ).getDataset(), label)

    
##Some bookkeeping paths I want to keep track of:
datapaths = {'Stripping21' : ['/LHCb/Collision12/Beam4000GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping21/90000000/',
                         '/LHCb/Collision12/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping21/90000000/',
                         '/LHCb/Collision11/Beam3500GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping21r1/90000000/',
                         '/LHCb/Collision11/Beam3500GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping21r1/90000000/'],}

## Add dataset type to the box for specified stripping stored in datapaths
def addDataToBox( dst, stripping='21'):
    pathlist = datapaths.get('Stripping'+stripping)
    if pathlist is None:
        print "No paths for that input available"
        return
    for path in pathlist:
        label = dst
        if 'Collision12' in path:
            label += ' 2012'
        elif 'Collision11' in path:
            label += ' 2011'
        else:
            label += ' '
            
        label += ' strip ' + stripping
        if 'MagUp' in path:
            label += ' MagUp'
        else:
            label += ' MagDown'

        #check its not already there
        if( len( box.select( name = label ) ) == 0 ):
            data = getDataset( path + dst )
            box.add(data, label)
        

###################
##Submitter class -- since I couldn't get the ganga GPI imports to work to put it in its own place!
###################

class Submitter:
    """Base class for submitting ganga jobs to the grid

    To make a particular submission, either instantiate the Submitter and set the attributes as you like, and then call submit(), or derive from this class if you need to override a method like modJob() which allows ganga jobs to be manipulated as you like just before submit.

    Attributes:
    
    dataToRun: list of tuples for data ("ganga box label",isMC)
    options: string path to options file to use or list of options files
    outputDirac: diracfile output or localfile
    outputs: list of filenames to output
    isTest: submit only a few files
    
    Methods:
    modJob( job ): Called on each job just before ganga submission.  Does nothing here, but you could override it to modify jobs as you need

    submit(): Submit the jobs as defined by the attributes

    """
    
    def __init__(self):
        self.dataToRun = [("MC",True),("Data 2012",False),]
        self.options = ""
        self.outputDirac = True
        self.outputs = ["",]
        self.isTest = False
        self._mcOpts = """
DaVinci().Simulation=True
        """
        self._dataOpts = """
DaVinci().DataType = '%s'
        """

    def modJob(self,job):
        print "Parent mod"


    def submit(self):
        print "######################################"
        print "Start submission with following setup:"
        print "dataToRun =", self.dataToRun
        print "options =", self.options
        print "outputs =", self.outputs
        print "######################################"

        #Check grid proxy will be sufficient
        gridProxy.renew(minValidity='24:00')
    
        #Create the outputfiles container
        if(self.outputDirac):
            outputfiles = [DiracFile(o) for o in self.outputs]
        else:
            outputfiles = [LocalFile(o) for o in self.outputs]
        
        import re
        #One job per dataset in the box
        for (label,isMC) in self.dataToRun:
            dataset = findDataInBox(label)
            if dataset is None:
                "Error: no data set with that label in the box, please add it first with addDataToBox or addFullPathToBox"
                continue
    
            print "Submitting", label, "with options", self.options, ", simulation?", isMC
        
            j = createGridJob(self.options + " " + label)

            #add options
            j.application.optsfile = self.options
        
            #handle extraOpts
            if isMC:
                extraOpts = self._mcOpts
            else:
                #look for the year for data
                try:
                    year = re.search("20[0-9][0-9]",label).group(0)
                except AttributeError:
                    try:
                        year = "20" + re.search("Collision([0-9][0-9])",dataset[0]).group(1)
                    except AttributeError:
                        print "Warning: couldn't get data year from box label or diracfile LFN, assume 2012"
                        year = "2012"
                    
                extraOpts = self._dataOpts % year
                    
            j.application.extraopts = extraOpts

            #input
            j.inputdata = dataset
            #output
            j.outputfiles = outputfiles
            
            self.modJob(j)
            j.submit()
            
