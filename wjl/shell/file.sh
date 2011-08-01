#!/bin/bash
file=a.out
if [ -e $file ]; then
    rm -rf $file
else
    touch $file
fi
exit 0;
