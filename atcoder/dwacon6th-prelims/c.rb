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
MOD = 10 ** 9 + 7

$n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

$fact = Array.new($n + 1, 1)
1.upto($n + 1) do |i|
  $fact[i] = ($fact[i - 1] * i) % MOD
end
$inv = Array.new($n + 1, 1)
$inv[$n + 1] = mod_pow($fact[$n + 1], MOD - 2, MOD) % MOD
($n + 1 - 1).downto(1) do |i|
  $inv[i] = ($inv[i + 1] * (i + 1)) % MOD
end

def comb(n, k)
  return $fact[n] * $inv[k] * $inv[n - k] % MOD
end

ans = 1
a.each do |ai|
  ans *= comb($n, ai)
  ans %= MOD
end
p ans
