def longest_common_substring(s1, s2)
  n = s1.size
  m = s2.size
  dp = Array.new(n + 1) { Array.new(m + 1, 0) }
  result = 0
  (n + 1).times do |i|
    (m + 1).times do |j|
      # i, j : 1-indexed
      if i == 0 || j == 0
        dp[i][j] = 0
      elsif s1[i - 1] == s2[j - 1]
        dp[i][j] = dp[i - 1][j - 1] + 1
        result = [dp[i][j], result].max
      else
        dp[i][j] = 0
      end
    end
  end
  result
end
a = gets.chomp
b = gets.chomp
p longest_common_substring(a, b)
