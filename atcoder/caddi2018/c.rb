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

n, p = gets.split.map(&:to_i)
ans = 1
factoring(p).each do |k, v|
  ans *= (k**(v/n)) if v >= n
end
p ans