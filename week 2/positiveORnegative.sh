#find +ve or -ve numbers
echo "entre a number"
read n
if [[ $n -lt 0 ]]; then
    #statements
    echo "negative number"
elif [[ $n -gt 0 ]]; then
    #statements
    echo "positive number"
else
    echo "zero"
fi
