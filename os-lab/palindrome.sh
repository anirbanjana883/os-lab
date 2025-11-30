echo "Enter the number"
read num

n=$num
rev=0
while [ $n -ne 0 ]
do
	digit=$((n%10))
	rev=$((rev*10+digit))
	n=$((n/10))
done

if [ $num -eq $rev ]
then 
	echo "Palindrome"

else
	echo "N0t Palidrome"
fi

