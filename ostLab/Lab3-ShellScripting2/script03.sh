echo "This file is $0"
echo "Enter 'a'"
read a
echo "Enter 'b'"
read b
echo "Enter 'c'"
read c
#d=`expr $b \* $b -4 \* $a \* $c`
d=$(echo "scale=3; $b*$b - 4*$a*$c" | bc -l )
x="0"

if [ $d -eq 0 ]
then 
x="1"
elif [ $d -gt 0 ]
then 
x="2"
else 
x="3" 
fi

if [ $b -lt 0 ]
then
	b=`expr $b \* -1`
	tmp=$(echo "scale=3; $b/(2*$a)" | bc -l )
else
	tmp=$(echo "scale=3; - $b/(2*$a)" | bc -l )
fi

t1=$(echo "scale=3; sqrt($d)/(2*$a)" | bc -l )

case $x in
"1")
	echo "Both roots are: $tmp"
;;
"2")
	#tmp=`expr \( - $b \/ \( 2 \* $a \) \)`
	#r1=`expr $tmp + \( $d \/ \( 2 \* $a \) \)`
	#r2=`expr $tmp - \( $d \/ \( 2 \* $a \) \)`
	r1=$(echo "scale=3; $tmp + $t1" | bc -l )
	r2=$(echo "scale=3; $tmp - $t1" | bc -l )
	echo "The roots are: $r1 and $r2"
;;
"3")
	echo "First root is: $tmp + $t1 i"
	echo "Second root is: $tmp - $t1 i" 
esac
echo "Done"
	
	



