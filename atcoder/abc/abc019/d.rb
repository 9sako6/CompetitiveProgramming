n = gets.to_i
# g = Array.new(n){[]}
m1 = 0
a1 = -1
2.upto(n) do |i|
  puts "? 1 #{i}"
  STDOUT.flush
  d = gets.to_i
  if d > m1
    m1 = d
    a1 = i
  end
end
m2 = 0
a2 = -1
1.upto(n) do |i|
  next if i == a1
  puts "? #{a1} #{i}"
  STDOUT.flush
  d = gets.to_i
  if d > m2
    m2 = d
    a2 = i
  end
end
puts "? #{a1} #{a2}"
STDOUT.flush
puts "! #{gets.to_i}"

