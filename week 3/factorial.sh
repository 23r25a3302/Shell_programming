# factorial
echo "enter number : "
read f
i=1
fact=1
while [ $i -le $f ]
do
fact=$(($i * $fact ))
i=$(( $i+1 ))
done
echo "factorial : $fact"
