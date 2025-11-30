echo "Enter first number"
read a
echo "Enter second number"
read b

c=$a

if [ $b -lt $c ]
then 
	c=$b
fi

while [ $c -ne 0 ]
do 
	x=`expr $a % $c`
	y=`expr $b % $c`

	if [ $x -eq 0 -a $y -eq 0 ]
	then 
		echo "GCD is $c"
		break
	fi
	c=`expr $c - 1`
done

