n = gets.to_i

t = n.times.map { gets.to_i }
T = t.inject(&:+)
dp = Array.new(n + 1) { Array.new(T + 1, false) }
dp[0][0] = true
n.times do |i|
  (T + 1).times do |j|
    dp[i + 1][j] |= dp[i][j]
    dp[i + 1][j + t[i]] |= dp[i][j]
  end
end

((T + 1) / 2).upto(T) do |a|
  if dp[n][a]
    puts a
    exit
  end
end
