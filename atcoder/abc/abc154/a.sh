read s t
read a b
read u
if [ $s = $u ]; then
  echo "$(($a-1)) $b"
else
  echo "$a $((b-1))"
fi