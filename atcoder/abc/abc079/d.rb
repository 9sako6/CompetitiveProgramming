require 'pp'
N=10
H,W=gets.split.map(&:to_i)
c = []
N.times do
  c << gets.split.map(&:to_i)
end
A = []
H.times do
  A << gets.split.map(&:to_i)
end

# ワーシャルフロイド
MAX = 1<<30
N.times do |k|
  N.times do |i|
    N.times do |j|
      c[i][j] = c[i][k]+c[k][j] if c[i][j] > c[i][k]+c[k][j]
    end
  end
end

ans = 0
H.times do |i|
  W.times do |j|
    if A[i][j] == -1 || A[i][j] == 1
      next
    else
      ans += c[A[i][j]][1]
    end
  end
end

p ans