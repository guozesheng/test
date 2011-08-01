#!/bin/bash

a=381
hello=$a

echo hello
echo $hello
echo ${hello}
echo "$hello"
echo "${hello}"
echo

hello="A B  C         D"
echo $hello
echo "$hello"
echo
echo '$hello'

hello=
echo "\$hello (null value) = $hello"
echo

var1=21 var2=22 var3=$V3
echo
echo "var1=$var1 var2=$var2 var3=$var3"
