#!/bin/bash

##This should set you up every time you run
##Specify individual package names you want to run their setup script as well

if [ -z "$VO_LHCB_SW_DIR" ]
then
    echo "LHCb environment not setup, please do so first"
    exit
fi

echo "Setting up for analysis"

#find where we are running and where the setup directory is
CURRDIR=$PWD
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

#add this directory to the python path if need be
if [[ :$PYTHONPATH: != *:"$DIR":* ]]
then
    export PYTHONPATH=$PYTHONPATH:$DIR
fi

#make a gangadir
mkdir -p $DIR/gangadir

if [ ! -f "$HOME/.gangarc" ]
then
    #create a gangarc
    /bin/bash -c "source $VO_LHCB_SW_DIR/group_login.sh && . SetupProject.sh ganga && ganga -g"
fi

#reset the gangadir in .gangarc
if grep -q -e '^#* *gangadir' $HOME/.gangarc
then
    sed -i "s;^#* *gangadir *= *.*;gangadir=$DIR/gangadir;g" $HOME/.gangarc
else
    sed -i "s;\[Configuration\];\[Configuration\]\n\ngangadir=$DIR/gangadir;" $HOME/.gangarc
fi

#copy the ganga.py -- would prefer to tell ganga where to find it but don't see how
rsync $DIR/analysisbase/python/ganga.py $HOME/.ganga.py

#setup each package if you want to specify
for package in $@
do
    echo "Setting up $package"
    cd $DIR/$package && ./setup.sh
    cd $CURRDIR
done
