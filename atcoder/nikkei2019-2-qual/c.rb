n = gets.to_i
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)

as = a.sort
bs = b.sort
n.times do |i|
  if as[i] > bs[i]
    puts "No"
    exit
  end
end
cnt = 0
n.times do |i|
  if a[i] > b[i]
    cnt += 1
  end
end
puts cnt <= n - 2 ? "Yes" : "No"
