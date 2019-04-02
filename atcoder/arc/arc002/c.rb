n = gets.to_i
s = gets.chomp

def cnt(s, l, r)
  res = 0
  i = 0
  while i < s.size
    res += 1
    if s[i, 2] == l || s[i, 2] == r
      i += 2
    else
      i += 1
    end
  end
  res
end

chs = ["A", "B", "X", "Y"]
ans = 100000
chs.each do |c1|
  chs.each do |c2|
    chs.each do |c3|
      chs.each do |c4|
        ans = [ans, cnt(s, c1 + c2, c3 + c4)].min
      end
    end
  end
end
p ans
