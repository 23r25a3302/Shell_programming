# numbers compare
echo "enter a , b , c values : "
read a
read b
read c
echo "a=$a, b=$b, c=$c"
if [[ $a -gt $b && $a -gt $c ]]; then
echo "a is greater than b,c"
elif [[ $b -gt $a && $b -gt $c ]]; then
echo "b is greater than a,c"
elif [[ $c -gt $a && $c -gt $b ]]; then
echo " c is greater than a,b"
else
echo "all are equal"
fi
