echo "This file is $0"
echo "Enter a number"
read n

fact=1

while [ $n -gt 0 ]
do
	fact=`expr $fact \* $n`
	n=`expr $n - 1`
done
echo "The factorial is: $fact"
echo "Done"
	
