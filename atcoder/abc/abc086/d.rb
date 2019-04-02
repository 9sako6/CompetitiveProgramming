def make_2dgrid(g)
  h = g.size
  s = Array.new(h + 1) { Array.new(h + 1, 0) }
  h.times do |i|
    h.times do |j|
      s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + g[i][j]
    end
  end
  s
end

def query(s, x1, x2, y1, y2)
  s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1]
end

n, k = gets.split.map(&:to_i)

k2 = 2 * k
gB = Array.new(k2) { Array.new(k2, 0) }
n.times do
  x, y, ci = gets.split
  x = x.to_i % k2
  y = (y.to_i + (ci == "W" ? k : 0)) % k2
  gB[x][y] += 1
end
ans = 0

sB = make_2dgrid(gB)

sBk2 = sB[k2]
sBk20 = sBk2[0]
sB0 = sB[0]
sB00 = sB0[0]
k.times do |i|
  sBi = sB[i]
  sBik = sB[i + k]
  sBik0 = sBik[0]
  sBik2 = sBi[k2]
  sBk2k2 = sBk2[k2]
  sB0k2 = sB0[k2]
  sBikk2 = sBik[k2]
  sBi0 = sBi[0]
  k.times do |j|
    ikjk = sBik[j + k]
    score = sBi[j] - sB0[j] - sBi0 + sB00
    score += sBk2[j] - sBik[j] - sBk20 + sBik0
    score += ikjk - sBi[j + k] - sBik[j] + sBi[j]
    score += sBik2 - sB0k2 - sBi[j + k] + sB0[j + k]
    score += sBk2k2 - sBikk2 - sBk2[j + k] + ikjk
    ans = score if score > ans
    score = n - score
    ans = score if score > ans
  end
end
p ans
