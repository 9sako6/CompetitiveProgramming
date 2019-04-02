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

n, k = gets.split.map(&:to_i)
mod = 10 ** 9 + 7

fact = Array.new(n + k)
fact[0] = 1
1.upto(n + k) do |i|
  fact[i] = (fact[i - 1] * i) % mod
end
ans = 0
if n <= k
  ans = fact[n]
  ans *= mod_pow(fact[k % n], mod - 2, mod)
  ans *= mod_pow(fact[n - (k % n)], mod - 2, mod)
else
  ans = fact[n + k - 1]
  ans *= mod_pow(fact[k], mod - 2, mod)
  ans *= mod_pow(fact[n - 1], mod - 2, mod)
end
p ans % mod
