# sum of natural nos
echo "enter a number : "
read n
t=$n
i=1
sum=0
while [ $i -le $n ]
do
sum=$(( $sum + $i ))
i=$(( $i + 1 ))
done
echo "sum of $t natural number is : $sum"
