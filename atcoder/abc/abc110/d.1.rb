def comb(n, k)
  res = 1
  i = n
  while i >= n-k+1
    res *= i
    i -= 1
  end
  while k > 0
    res /= k
    k -= 1
  end
  res
end
MOD = 10**9+7
n, m = gets.split.map(&:to_i)
i = 2
f = Hash.new(0)
while i * i <= m
  while m % i == 0
    m /= i
    f[i] += 1
  end
  i += 1
end
f[m] = 1 if m != 1
ans = 1
f.each do |k,v|
  ans *= comb(n+v-1, v)
  ans %= MOD
end
p ans
