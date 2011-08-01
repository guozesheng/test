#!/bin/bash
echo -p "Please input the filename" fileuser
filename = ${fileuser:-"filename"}

date1 = `date --date = '2 days ago' +%Y%m%d`
date2 = `date --date = '1 days ago' +%Y%m%d`
date3 = `date +%Y%m%d`

file1 = "$filename""$date1"
file2 = "$filename""$date2"
file3 = "$filename""$date3"
