echo "Number of users: `who | wc -l`" > file02.txt
a=`ls | wc -l`
b=`ls -d | wc -l`
echo "Number of files: `expr $a - $b`" >> file02.txt
