echo "Enter the number "
read num

n=$num
count=0
while [ $n -ne 0 ]
do
	n=`expr $n / 10 `
	count=`expr $count + 1 `
done

echo "number of digit is $count"
