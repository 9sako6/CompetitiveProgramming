n = rand(2..10)
k = rand(2..10)
a = Array.new(n) { rand(1..20) }
s = Array.new(k) { rand(1..20) }
puts "#{n} #{k}"
puts a * " "
puts s * " "
