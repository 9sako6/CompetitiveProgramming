n, z, w = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

# ref: http://drken1215.hatenablog.com/entry/2019/05/11/133400
# dp[山札からとった枚数][後手かどうか] := その状態からスタートしたときの、最終的なカードの数値の差の最適値（先手なら最大値、後手なら最小値）
dp = Array.new(n) { Array.new(2, 0) }
(n - 1).downto(0) do |i|
  # 先手
  y = i == 0 ? w : a[i - 1]
  dp[i][0] = (y - a[n - 1]).abs # のこりすべてとる
  (i + 1).upto(n - 1) do |j|
    dp[i][0] = [dp[i][0], dp[j][1]].max
  end

  # 後手
  x = i == 0 ? z : a[i - 1]
  dp[i][1] = (x - a[n - 1]).abs # のこりすべてとる
  (i + 1).upto(n - 1) do |j|
    dp[i][1] = [dp[i][1], dp[j][0]].min
  end
end

p dp[0][0]
