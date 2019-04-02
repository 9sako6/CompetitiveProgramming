n = gets.to_i
a = gets.split.map(&:to_i)

sum = a.inject(&:+)

dp = Array.new(n + 1){Array.new(sum + 1, false)}
dp[0][0] = true
(1..n).each do |k|
  (sum+1).times do |val|
    dp[k][val] = dp[k - 1][val] || dp[k-1][val - a[k-1]]
  end
end

p dp[n].count(true)