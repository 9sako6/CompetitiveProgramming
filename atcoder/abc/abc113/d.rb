mod = 1000000007
h, w, k = gets.split.map(&:to_i)
dp = Array.new(h + 1) { Array.new(w + 1, 0) }
dp[0][0] = 1
h.times do |hi|
  (0...(1 << (w - 1))).each do |bit|
    ng = false
    (w - 1).times do |wi|
      if bit[wi] == 1 && bit[wi + 1] == 1
        ng = true
      end
    end
    next if ng
    w.times do |wi|
      target = wi
      if wi == 0
        target = wi + 1 if bit[wi] == 1
      elsif wi == w - 1
        target = wi - 1 if bit[wi - 1] == 1
      else
        if bit[wi - 1] == 1
          target = wi - 1
        elsif bit[wi] == 1
          target = wi + 1
        end
      end
      dp[hi + 1][target] += dp[hi][wi]
      dp[hi + 1][target] %= mod
    end
  end
end

p dp[h][k - 1]
