read h
n=0
while [ $h -gt 0 ]; do
  h=$(($h / 2))
  n=$(($n + 1))
done
ans=0
for((i=0;i<$n;i++));do
  ans=$((ans + 2**$i))
done
echo $ans