echo "This file is $0"
echo "Enter a number n"
read n
i=1
while [ $i -lt $n ]
do
	if [ `expr $i % 2` -eq 1 ]
	then
		echo $i
	fi
	i=`expr $i + 1`
done
echo "Done"
