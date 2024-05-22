# reverse of a number
echo "enter number : "
read n
rev=0
while [ $n -gt 0 ]
do
rem=$(( $n % 10 ))
rev=$(( $rev * 10 + rem ))
n=$(( $n / 10 ))
done
echo "reverse of $n : $rev"
