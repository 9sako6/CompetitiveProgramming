n=gets.to_i
a = n.times.map{gets.to_i}
ans = 0
now = 1
while now != 2
  now = a[now-1]
  ans += 1
  if ans > 2*n
    ans = -1
    break
  end
end

puts ans
