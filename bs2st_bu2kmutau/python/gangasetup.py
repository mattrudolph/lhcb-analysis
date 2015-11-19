
#Make sure we have dimuon dst available
addDataToBox( 'DIMUON.DST' )

#add some MC we want
mymcdict = {'Bs2st->(Bu->Kmumu)K MagDown' : "/MC/2012/Beam4000GeV-2012-MagDown-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14c/Stripping20NoPrescalingFlagged/17114080/ALLSTREAMS.DST",
            'Bs2st->(Bu->KJpsi)K MagDown' : "/MC/2012/Beam4000GeV-2012-MagDown-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14c/Stripping20NoPrescalingFlagged/17114081/ALLSTREAMS.DST",
            'Bs2st->(Bu->Kmutau)K MagDown' : "/MC/2012/Beam4000GeV-2012-MagDown-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14c/Stripping20NoPrescalingFlagged/17113080/ALLSTREAMS.DST",
            'Bs2st->(Bu->Kmumu)K MagUp' : "/MC/2012/Beam4000GeV-2012-MagUp-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14c/Stripping20NoPrescalingFlagged/17114080/ALLSTREAMS.DST",
            'Bs2st->(Bu->KJpsi)K MagUp' : "/MC/2012/Beam4000GeV-2012-MagUp-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14c/Stripping20NoPrescalingFlagged/17114081/ALLSTREAMS.DST",
            'Bs2st->(Bu->Kmutau)K MagUp' : "/MC/2012/Beam4000GeV-2012-MagUp-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14c/Stripping20NoPrescalingFlagged/17113080/ALLSTREAMS.DST",
}

for label,path in mymcdict.iteritems():
    addFullPathToBox( path, label )

