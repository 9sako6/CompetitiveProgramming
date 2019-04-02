x, y = gets.split.map(&:to_i)
a = [100000, 200000, 300000].reverse
s = a[x - 1]
s = 0 if s.nil?
t = a[y-1]
t = 0 if t.nil?
cnt = s + t
if x == 1 && y == 1
  cnt += 400000
end
p cnt