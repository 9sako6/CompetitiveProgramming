a,b=gets.not_nil!.split.map(&.to_i)
puts (a*b).odd? ? "Odd" : "Even"