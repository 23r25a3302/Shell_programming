# find character type
echo "enter a character : "
read c
case $c in
([a-z]) echo "lowerCase";;
([A-Z]) echo "upperCase";;
([0-9]) echo "digits";;
(*) echo "specialChar";;
esac
