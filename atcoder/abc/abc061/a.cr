a,b,c=gets.not_nil!.split.map(&.to_i)
puts (c >= a && b >= c) ? "Yes" : "No"