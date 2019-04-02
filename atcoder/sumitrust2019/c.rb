x = gets.to_i
a = [100, 101, 102, 103, 104, 105]
dp = Array.new(101000, 0)
dp[0] = 1
100010.times do |i|
  a.each do |c|
    # next if i - c < 0
    dp[i + c] = 1 if dp[i] == 1
    # p i if dp[i] == true
  end
end

p dp[x]
# pp dp
# p dp[0..x]