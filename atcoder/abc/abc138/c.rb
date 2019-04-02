n=gets.to_i
v=gets.split.map(&:to_i)
v.sort!
ans = (v[0] + v[1]) / 2.0
if n <= 2
  puts ans
  exit
else
  (2...n).each do |i|
    ans = (ans + v[i]) / 2.0
  end
  puts sprintf("%.10f", ans)
  exit
end


