# print table using loop
echo "enter a table no : "
read n
for (( i = 1; i <= 10; i++ )); do
res=$(( n * i ))
echo "$n * $i = $res "
done
