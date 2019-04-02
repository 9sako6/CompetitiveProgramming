A, B, C, = gets.split.map(&:to_f)

def f(t)
  A * t + B * Math.sin(C * t * Math::PI)
end

ok = -10000.0
ng = 10000.0
while (ok - ng).abs > 10 ** (-12)
  mid = (ok + ng) / 2.0
  if f(mid) < 100.0
    ok = mid
  else
    ng = mid
  end
end

p ok
