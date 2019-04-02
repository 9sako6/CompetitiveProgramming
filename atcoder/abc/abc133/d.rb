n=gets.to_i
as=gets.split.map(&:to_i)
b = as[-1]*2
ans = []
bunshi = 0

as.each_with_index do |a, i|
  break if i == n-1
  if i.even?
    bunshi -= a*2
  else
    bunshi += a*2
  end
end
bunshi -= b
ans << (bunshi/(-2))

(1...n).each do |i|
  ans << as[i-1]*2 - ans[i-1]
end

puts ans * ' '
