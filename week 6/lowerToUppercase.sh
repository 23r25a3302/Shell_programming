# change lowercase to uppercase
echo -n "Enter File Name : "
read fileName

if [ ! -f $fileName ]; then
    echo "Filename $fileName does not exist."
    exit 1
fi

tr '[a-z]' '[A-Z]' < $fileName
