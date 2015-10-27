#!/bin/bash

if [ -z "$VO_LHCB_SW_DIR" ]
then
    echo "LHCb environment not setup, please do so first"
    exit
fi

#make a gangadir
mkdir -p gangadir

if [ ! -f "$HOME/.gangarc" ]
then
    #create a gangarc
    /bin/bash -c 'source %s/group_login.sh && . SetupProject.sh ganga && ganga -g'
fi

#reset the gangadir
if grep -q -e '^#* *gangadir' $HOME/.gangarc
then
    sed -i "s;^#* *gangadir *= *.*;gangadir=$PWD/gangadir;g" $HOME/.gangarc
else
    sed -i "s;\[Configuration\];\[Configuration\]\n\ngangadir=$PWD/gangadir;" $HOME/.gangarc
fi

#copy the ganga.py -- would prefer to tell ganga where to find it but don't see how
cp analysisbase/python/ganga.py $HOME/.ganga.py
