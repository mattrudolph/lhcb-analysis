#!/bin/bash

if [ -n "$VO_LHCB_SW_DIR" ]
then
    #run the gangasetup
    /bin/bash -c "source $VO_LHCB_SW_DIR/group_login.sh && . SetupProject.sh ganga && ganga python/gangasetup.py"
fi
