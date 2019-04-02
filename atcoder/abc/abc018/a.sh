# read a
# read b
# read c
# ruby -e "a=[$a,$b,$c];a.map{|x|p a.select{|b|b>x}.size+1}"
read A
read B
read C
echo "$A A\n$B B\n$C C"|sort -nr|cut -f 2
# echo $S