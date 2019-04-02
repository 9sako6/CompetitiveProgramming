n, l = gets.split.map(&:to_i)
x = {}
gets.split.map(&:to_i).map { |xi| x[xi] = xi }

t1, t2, t3 = gets.split.map(&:to_i)

dp = Array.new(l + 10, Float::INFINITY)
dp[0] = 0
(0...l).each do |i|
  dp[i + 1] = [dp[i + 1], dp[i] + t1 + (x[i] ? t3 : 0)].min # action1
  if i + 2 <= l
    dp[i + 2] = [dp[i + 2], dp[i] + t2 + t1 + (x[i] ? t3 : 0)].min # action2
  else
    dp[l] = [dp[l], dp[i] + 0.5 * t2 + 0.5 * t1 + (x[i] ? t3 : 0)].min # action2
  end
  if i + 4 <= l
    dp[i + 4] = [dp[i + 4], dp[i] + t1 + 3 * t2 + (x[i] ? t3 : 0)].min # action3
  else
    dp[l] = [dp[l], dp[i] + 0.5 * t1 + (l - i - 0.5) * t2 + (x[i] ? t3 : 0)].min # action3
  end
end
p dp[l].to_i
