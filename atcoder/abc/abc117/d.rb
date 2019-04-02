N, K = gets.split.map(&:to_i)
as = gets.split.map(&:to_i)
D = 40
# dp[i][smaller]
# Xの上からi[0, 40]桁（2進数）目までの数を確定させたときのスコアの最大値
# smaller=1 Xの桁がKの当該桁より小さい
# smaller=0 Xの桁がKの当該桁と一致
dp = Array.new(D + 1) { Array.new(2, -1) }
dp[0][0] = 0
(0...D).each do |d|
  mask = 1 << (D - d - 1)
  # d桁目が1のAの個数
  num = as.count { |a| a & mask > 0 }
  # Xのd桁目を0,1にした時のスコア
  cost0 = mask * num
  cost1 = mask * (N - num)

  # 遷移
  # 1. smaller=1 -> smaller=1
  if dp[d][1] != -1 # ?
    dp[d+1][1] = [
      dp[d+1][1],
      dp[d][1] + [cost0, cost1].max
    ].max
  end

  # 2. smaller=0 -> smaller=1
  # Kのd桁目が1だったらXのd桁目は0にする
  if K & mask > 0
    dp[d + 1][1] = dp[d][0] + cost0 if dp[d + 1][1] < dp[d][0] + cost0
  end

  # 3. smaller=0 -> smaller=0
  dp[d + 1][0] = dp[d][0] + (K & mask > 0 ? cost1 : cost0)
end
p [dp[D][0], dp[D][1]].max
