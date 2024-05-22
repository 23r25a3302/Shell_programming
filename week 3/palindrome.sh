# palindrome or not
echo "enter a number : "
read n
t=$n
rev=0
while [ $n -gt 0 ]
do
rem=$(( $n % 10 ))
rev=$(( $rev * 10 + $rem ))
n=$(( $n / 10 ))
done
if [[ $rev -eq $t ]]; then
echo "$t is palindrome"
else
echo "$t is not palindrome"
fi
