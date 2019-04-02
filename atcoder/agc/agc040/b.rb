n = gets.to_i
lr = []
mx = -Float::INFINITY # maximum of L
mn = Float::INFINITY # minimum of R
n.times do
  # [l, r)
  l, r = gets.split.map(&:to_i)
  l -= 1
  mx = l if l > mx
  mn = r if r < mn
  lr << [l, r]
end

ans = 0
lr.each do |l, r|
  tmp = [0, mn - mx].max + r - l
  ans = tmp if tmp > ans
end
t = []
n.times do |i|
  a = [0, mn - lr[i][0]].max
  b = [0, lr[i][1] - mx].max
  t << [b, -a]
end
t.sort!
w = Float::INFINITY
n.times do |i|
  z = t[i]
  zb = -z[1]
  if (i != 0)
    ans = w + z[0] if w + z[0] > ans
  end
  w = zb if w > zb
end
p ans
