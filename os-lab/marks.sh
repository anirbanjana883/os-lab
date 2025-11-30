echo "Enter percent for os"
read os
echo "Enter percent for cc"
read cc
echo "Enter percent for dm"
read dm

a=`expr $os + $cc`
b=`expr $a + $dm`

total=`expr $b / 3`

if [ $total -ge 50 ] 
then 
	echo "Passed"
elif [ total -ge 40 -a total -lt 50 ]
then
	echo "Improvement exam"
else 
	echo "Failed"
fi	
