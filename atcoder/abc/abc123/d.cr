x,y,z,k=gets.not_nil!.split.map(&.to_i64)
a=gets.not_nil!.split.map(&.to_i64)#.sort_by{|x| -x}
b=gets.not_nil!.split.map(&.to_i64)#.sort_by{|x| -x}
c=gets.not_nil!.split.map(&.to_i64)#.sort_by{|x| -x}
ab = a.product(b).map{|x,y|x+y}.sort.last(k).reverse
abc = c.product(ab).map{|x,y|x+y}.sort.last(k).reverse
puts abc.join("\n")
