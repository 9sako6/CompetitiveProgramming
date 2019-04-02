def check(a, b, x, n)
  d = n.to_s.size
  s = a * n + b * d
  # p [n, s, x]
  return s <= x
end

a, b, x = gets.split.map(&:to_i)

ok = 0
ng = 10 ** 10
while (ok - ng).abs > 1
  mid = (ok + ng) / 2
  if check(a, b, x, mid)
    ok = mid
  else
    ng = mid
  end
end

p [ok, 10 ** 9].min
