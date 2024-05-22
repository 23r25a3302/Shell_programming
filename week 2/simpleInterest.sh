# simple interest
echo "enter p, t, r values : "
read p
read t
read r
h=100
s=$(($p*$t*$r/$h))
echo "simple interest : $s"
tot=$(($p+$s))
echo "total amount : $tot"
