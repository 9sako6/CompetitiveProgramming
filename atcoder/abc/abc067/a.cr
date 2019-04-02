a, b = gets.not_nil!.split.map(&.to_i)
puts [a,b,a+b].any?{|x| x%3==0} ? "Possible" : "Impossible"
