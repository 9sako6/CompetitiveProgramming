n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

if a.max < k
  puts "IMPOSSIBLE"
  exit
elsif a.any? { |ai| ai == k }
  puts "POSSIBLE"
  exit
end
g = a.inject(0) { |memo, i| memo.gcd(i) }
if k % g == 0
  puts "POSSIBLE"
else
  puts "IMPOSSIBLE"
end