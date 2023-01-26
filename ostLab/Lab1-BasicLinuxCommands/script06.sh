a=`ls | wc -l`
b=`ls -d | wc -l`
echo `expr $a - $b`
