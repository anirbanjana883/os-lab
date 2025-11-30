
echo "enter number of element"
read n

echo "Enter number of elements "

for((i=0;i<n;i++))
do
	read a[$i]
done

max=${a[0]}
min=${a[0]}

for((i=0;i<n;i++))
do
	if [ ${a[i]} -gt $max ]
	then
		max=${a[i]}
	fi

	if [ ${a[$i]} -lt $min ]
	then 
		min=${a[i]}
	fi
done

echo "max number is $max min number is $min"
