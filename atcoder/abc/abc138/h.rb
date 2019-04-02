require "benchmark"

def guchoku(l)
  res = 0
  1.upto(l) do |i|
    cnt = 0
    17.times do |j|
      cnt += 1 if i[j] == 1
    end
    res += 1 if cnt == 2
  end
  res
end

def solve(l)
  dp = Array.new(50) { Array.new(2) { Array.new(3, 0) } } # dp[i][j][k]
  dp[-1][1][0] = 1
  48.downto(0) do |i|
    3.times do |k|
      dp[i][(l[i] == 0 ? 1 : 0)][k] += dp[i + 1][1][k]
      dp[i][0][k] += dp[i + 1][0][k]
      next if k == 2
      dp[i][1][k + 1] += dp[i + 1][1][k] if l[i] == 1
      dp[i][0][k + 1] += dp[i + 1][0][k]
    end
  end
  dp[0][1][2] + dp[0][0][2]
end

l = gets.to_i
# Benchmark.bm do |x|
#   #x.report { guchoku(l) }
#   x.report { solve(l) }
# end
p solve(l)

__END__
3 <= l <= 10^8
が与えられる。立っているbit数が2の個数を求めよ
