n, k = gets.split.map(&:to_i)
p ((k - 1) * (n - k) * 6 + (n - k) * 3 + (k - 1) * 3 + 1).to_f / (n ** 3)
