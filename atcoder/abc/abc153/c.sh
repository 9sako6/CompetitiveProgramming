read n k
if [ $k = 0 ]; then
    echo $(($(sed -e 's/ /+/g')))
else
    echo $(($(tr ' ' $'\n' | LANG=C sort -rn | sed -e '1,'${k}'d' | tr $'\n' '+')0))
fi
