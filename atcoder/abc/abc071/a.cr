x,a,b=gets.not_nil!.split.map(&.to_i)
puts (x-a).abs > (x-b).abs ? "B" : "A"