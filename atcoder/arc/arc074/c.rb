h, w = gets.split.map(&:to_i)

def min(ans, arr)
  d = arr.minmax.inject(&:-).abs
  return ((d < ans) ? d : ans)
end

def solver(h, w)
  ans = 1e11
  (h + 1).times do |i|
    sa = w * i
    # tate
    wi = w / 2
    sb = (h - i) * wi
    sc = (h - i) * (w - wi)
    ans = min(ans, [sa, sb, sc])
    # yoko
    hi = (h - i) / 2
    sb = hi * w
    sc = (h - hi - i) * w
    ans = min(ans, [sa, sb, sc])
  end
  ans
end
p [solver(h, w), solver(w, h)].min
