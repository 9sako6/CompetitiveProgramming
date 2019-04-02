n, a, b = gets.split.map(&:to_i)
mod = 10 ** 9 + 7

def mod_pow(a, n, mod)
  res = 1
  x = a % mod
  while n > 0
    res = res * x % mod if n.odd?
    x = x * x % mod
    n >>= 1
  end
  return res
end

# n = gets.to_i
# k = gets.to_i
# mod = 10 ** 9 + 7

ans = (mod_pow(2, n, mod) - 1) % mod

# nCa
nc = [1]
1.upto(2 * (10 ** 5) + 10) do |k|
  nca *= (n - k + 1)
  nca %= mod
end

# p ans
# max = 2 * (10 ** 5) + 10
# fact = Array.new(max, 1)
# 1.upto(max) do |i|
#   fact[i] = (fact[i - 1] * i) % mod
# end
# inv = Array.new(max, 1)
# inv[max] = mod_pow(fact[max], mod - 2, mod) % mod
# (max - 1).downto(1) do |i|
#   inv[i] = (inv[i + 1] * (i + 1)) % mod
# end

# ans -= fact[n] * inv[n - a] * inv[a] % mod
# ans -= fact[n] * inv[n - b] * inv[b] % mod
# p ans
