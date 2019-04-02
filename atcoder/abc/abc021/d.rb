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

n = gets.to_i
k = gets.to_i
mod = 10 ** 9 + 7
fact = Array.new(n + k, 1)
1.upto(n + k) do |i|
  fact[i] = (fact[i - 1] * i) % mod
end
inv = Array.new(n + k, 1)
inv[n + k] = mod_pow(fact[n + k], mod - 2, mod) % mod
(n + k - 1).downto(1) do |i|
  inv[i] = (inv[i + 1] * (i + 1)) % mod
end

ans = fact[n + k - 1] * inv[k] * inv[n - 1] % mod
p ans
