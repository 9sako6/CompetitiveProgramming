n = gets.to_i
c = Hash.new{|h, k| h[k] = 0}
n.times do
  s = gets.chomp
  c[s] += 1
end
m = c.values.max
c.each do |k, v|
  if v == m
    puts k
    exit
  end
end