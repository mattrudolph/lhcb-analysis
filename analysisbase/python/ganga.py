

import os

def getAllCompleted( j ):
    for sj in j.subjobs:
        if sj.status == "completed":
            for f in sj.outputfiles.get(DiracFile):
                if not os.path.exists(sj.outputdir + '/' + f.namePattern):
                    f.localDir = sj.outputdir
                    print "Downloading " + sj.outputdir + '/' + f.namePattern
                    f.get()
