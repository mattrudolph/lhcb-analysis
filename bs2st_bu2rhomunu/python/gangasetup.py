#Make sure we have dimuon dst available
addDataToBox( 'SEMILEPTONIC.DST' )

#add some MC we want
mymcdict = {'Bu->rhomunu MagDown' : "/MC/2012/Beam4000GeV-2012-MagDown-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14a/Stripping20NoPrescalingFlagged/12513001/ALLSTREAMS.DST",
            'Bu->rhomunu MagUp' : "/MC/2012/Beam4000GeV-2012-MagUp-Nu2.5-Pythia8/Sim08g/Digi13/Trig0x409f0045/Reco14a/Stripping20NoPrescalingFlagged/12513001/ALLSTREAMS.DST",
}

for label,path in mymcdict.iteritems():
    addFullPathToBox( path, label )

