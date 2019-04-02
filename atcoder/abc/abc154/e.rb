s = gets.chomp
m = gets.to_i

n = s.size

dp = Array.new(110) { Array.new(4) { Array.new(2, 0) } }

dp[0][0][0] = 1

n.times do |i|
  4.times do |j|
    2.times do |k|
      x = s[i].to_i
      10.times do |d|
        ni = i + 1
        nj = j
        nk = k
        nj += 1 if d != 0
        next if nj > m
        if k == 0
          next if d > x
          nk = 1 if d < x
        end
        dp[ni][nj][nk] += dp[i][j][k]
      end
    end
  end
end
p dp[n][m][0] + dp[n][m][1]