"""
Helper functions for use inside ganga

"""


import os

#use bookkeeping query to get a path and return the dataset
def getDataset( bkpath, flag='OK' ):
    return BKQuery( bkpath, dqflag=[flag]).getDataset()

#download output diracfiles for a job if they are done and do not exist yet locally
def getAllCompleted( job ):
    for sj in job.subjobs:
        if sj.status == "completed":
            for f in sj.outputfiles.get(DiracFile):
                if not os.path.exists(sj.outputdir + '/' + f.namePattern):
                    f.localDir = sj.outputdir
                    print "Downloading " + sj.outputdir + '/' + f.namePattern
                    f.get()




##Some bookkeeping paths I want to keep track of:
datapaths = {'Stripping21' : ['/LHCb/Collision12/Beam4000GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping21/90000000/',
                         '/LHCb/Collision12/Beam4000GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping21/90000000/',
                         '/LHCb/Collision11/Beam3500GeV-VeloClosed-MagUp/Real Data/Reco14/Stripping21r1/90000000/',
                         '/LHCb/Collision11/Beam3500GeV-VeloClosed-MagDown/Real Data/Reco14/Stripping21r1/90000000/'],}

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
        
