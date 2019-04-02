L, R=gets.split.map(&:to_i)
if R-L >= 2019
  puts 0
  exit
end
ans = 10**9
(L..R).each do |i|
  (i..R).each do |j|
    next if i==j
    ans = [ans, i*j%2019].min
  end
end
puts ans
    
  
