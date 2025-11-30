echo "enter number of element"
read n

echo "Enter number of elements "

for((i=0;i<n;i++))
do
        read a[$i]
done

echo "Enter target"
read target

idx=-1

for((i=0;i<n;i++))
do
        if [ ${a[i]} -eq $target ]
        then
		idx=$i
		break
	fi
               
done

if [ $idx -eq -1 ]
then
	echo "target not found"
else
	echo "target found at index $idx"
fi
