# reverse of string
echo "enter string "
read str
len=${#str}
for (( i = $len-1; i >= 0; i-- )); do
    #statements
    rev="$rev${str:$i:1}"
done
echo "reverse of string $str : $rev"
