n, k , q = gets.split.map(&:to_i)
imos = Array.new(n+1, 0)
q.times do
  ai = gets.to_i
  ai -= 1
  imos[0] -= 1
  imos[ai] += 1
  imos[ai+1] -= 1
  imos[n] += 1
end
sum = Array.new(n, 0)
sum[0] = imos[0]
(1...n).each do |i|
  sum[i] = imos[i] + sum[i-1]
end
sum.map{|x| x + k}.each do |x|
  if x > 0
    puts "Yes"
  else
    puts "No"
  end
end