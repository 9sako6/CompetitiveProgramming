n = gets.to_i
d = n.to_s.size
sr = n.to_s.chars.reverse
ans = 0
1.upto(11) do |i|
  next if d < i
  # 今i桁目をみている
  a = n / (10 ** i)
  add = a * (10 ** (i - 1))
  if sr[i - 1] == "1"
    add += ((n % (10 ** i)) - (10 ** (i - 1)) + 1)
  else
    add += (10 ** (i - 1)) unless sr[i - 1] == "0"
  end
  ans += add
end
p ans
