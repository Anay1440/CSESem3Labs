echo The name of the script is $0
echo The first argument is $1
echo A list of all the arguments is $*
echo This script places the date into a temporary file
echo Called $1.$$
date > $1.$$
echo The contents of the file are
cat $1.$$
rm $1.$$
