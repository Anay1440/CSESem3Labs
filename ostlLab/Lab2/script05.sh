echo This file is $0
cat $1 $2 >> $1.$$
sort -n $1.$$ | uniq
echo Done
