# find odd or even
echo "Enter a number:"
read n
if [[ `expr $n % 2` == 0 ]]; then
    echo "Even"
else
    echo "Odd"
fi
