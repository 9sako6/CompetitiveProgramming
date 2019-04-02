n = gets.to_i
c = Hash.new(0)
0.upto(n) do |i|
  s = i.to_s
  c["#{s[0]}#{s[-1]}"] += 1
end
ans = 0
1.upto(9) do |i|
  1.upto(9) do |j|
    ans += c["#{i}#{j}"] * c["#{j}#{i}"]
  end
end
p ans
