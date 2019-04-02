read h n
read s
a=$(($(echo $s | sed -e 's/ /+/g')))
if [ $h -le $a ]; then
  echo Yes
else
  echo No
fi