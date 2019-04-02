n=gets
ws=gets.split.map(&:to_i)
sum = ws.inject(:+)
ans = 1<<30
prev_s1 = 0
prev_s2 = sum

ws.each do |w|
  prev_s1 += w
  prev_s2 -= w
  if (prev_s1 - prev_s2).abs < ans
    ans = (prev_s1 - prev_s2).abs
  end
end

p ans


