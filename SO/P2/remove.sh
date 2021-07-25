cat $2

grep -v $1 $2 >"/tmp/temp.txt"
mv "/tmp/temp.txt" $2
