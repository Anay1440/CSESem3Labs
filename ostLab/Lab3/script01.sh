echo "This file is $0"
echo "Enter a number"
read number
remainder=`expr $number % 2`
if [ $remainder -eq 0 ]
then
echo "The number entered is even" 
else
echo "The number entered is odd"
fi
echo "Done"
