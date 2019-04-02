read n
m=$(tr ' ' '\n' | LANG=C sort -u | wc -l | tr -d ' ')
if [ $n != $m ]; then
  echo "NO"
else
  echo "YES"
fi
