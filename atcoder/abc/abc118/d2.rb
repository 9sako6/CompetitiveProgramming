N, M = gets.split.map(&:to_i)
A = gets.split.map(&:to_i)
A.sort_by!{|x| -x}
match = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
def max(s1, s2)
  s1 > s2 ? s1 : s2
end

# dp[i]: i本使って作れる最大桁数
dp = Array.new(N+1, 0)
0.upto(N) do |i|
  A.each do |a|
    dp[i] = max(dp[i-match[a]]+1, dp[i]) if i-match[a] >= 0
  end
end

ans = 0
r_d = dp[N]
r_m = N
while r_m > 0
  A.each do |a|
    p ans
    if dp[r_m-match[a]] == r_d - 1
      ans = ans*10 + a
      r_d -= 1
      r_m -= match[a]
      # break
    end
  end
end
p ans