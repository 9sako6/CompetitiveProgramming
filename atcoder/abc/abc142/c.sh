read n
echo $(tr ' ' '\n' | nl | sort -nk 2 | cut -f 1)