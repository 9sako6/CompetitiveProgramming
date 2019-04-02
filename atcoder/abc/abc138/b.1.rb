n=gets
a=gets.split.map(&:to_i)
seki = a.inject(1){|x, ai| x*ai}
bunbo = 0.0
a.each do |ai|
  bunbo += 1.0*seki / ai
end

puts sprintf("%.10f", seki/bunbo)
