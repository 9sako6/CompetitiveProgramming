def factoring(n)
  # 素因数分解O(√n)
  res = Hash.new(0)
  i = 2
  while i*i <= n
    while n % i == 0
      res[i] += 1
      n /= i
    end
    i += 1
  end
  res[n] = 1 if n != 1
  res
end

def comb(n, m)
  res = 1
  cnt = 0
  while cnt < m
    res *= n
    n -= 1
    cnt += 1
  end
  while m > 0
    res /= m
    m -= 1
  end
  res
end

N,M=gets.split.map(&:to_i)
ans = 1
MOD = 10**9+7
factoring(M).each do |k,v|
  ans *= comb(N+v-1, v)
  ans %= MOD
end
p ans