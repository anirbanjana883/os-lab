echo "Enter a "
read a
echo "Enter b"
read b

add=`expr $a + $b`
sub=`expr $a - $b`
mul=`expr $a \* $b`
div=`expr $a / $b`

echo "Addition is $add"
echo "Substraction is $sub"
echo "Multiplication is $mul"
echo "Division is $div"
