echo "Enter days"
read d

years=`expr $d / 365`
remainingdays=`expr $d % 365`
weeks=`expr $remainingdays / 7`
day=`expr $remainingdays % 7`

echo "years is $years"
echo "weeks is $weeks"
echo "days is $day"
