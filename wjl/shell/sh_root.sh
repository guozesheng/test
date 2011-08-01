#!/bin/bash
ROOt_UID=0
if [ "$UID" -ne "$ROOt_UID" ]
then
    echo "Must be root to run this script."
    exit $E_NOTROOT
fi
ls
