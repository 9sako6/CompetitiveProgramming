n = gets.to_i
a = gets.split.map(&:to_i)

dp = Array.new(n + 1) { Array.new(2, 0) }
# dp[i][j]:= i(i-indexed)番目までの餅を処理したうえでi番目の餅がずんだ餅(j = 1) / 餅(j = 0)である並びのうち、最適なものにおけるずんだ餅の数
n.times do |i|
  dp[i+1][0] = dp[i].max
  if i != 0 && a[i] != a[i-1]
    dp[i+1][1] = dp[i][0] + 1
  else
    dp[i+1][1] = dp[i].max + 1
  end
end
p dp[n].max
