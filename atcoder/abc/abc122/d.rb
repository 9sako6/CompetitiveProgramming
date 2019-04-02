N = gets.to_i
MOD = 10 ** 9 + 7

# A: 0, G: 1, C: 2, T: 3
# NG: AGC, 1回入れ替えてAGC
# AGC, GAC, ACG, A?GC, AG?C
# 012, 102, 021, 0?12, 01?2

# dp: 文字数、最後から3,2,1文字目がいくつあるか
dp = Array.new(101) { Array.new(4) { Array.new(4) { Array.new(4, 0) } } }
# dp[0][3][3][3] = 1
dp[1][0][3][3] = 1
dp[1][1][3][3] = 1
dp[1][2][3][3] = 1
dp[1][3][3][3] = 1

N.times do |i|
  4.times do |j| # 最後から1文字目の文字
    4.times do |k|
      4.times do |l|
        next if dp[i][j][k][l] == 0
        4.times do |c|
          next if c == 2 && j == 1 && k == 0
          next if c == 2 && j == 0 && k == 1
          next if c == 1 && j == 2 && k == 0
          next if c == 2 && j == 1 && l == 0
          next if c == 2 && k == 1 && l == 0
          dp[i + 1][c][j][k] += dp[i][j][k][l]
          dp[i + 1][c][j][k] %= MOD
        end
      end
    end
  end
end

ans = 0
4.times do |j|
  4.times do |k|
    4.times do |l|
      ans += dp[N][j][k][l]
      ans %= MOD
    end
  end
end

puts ans
