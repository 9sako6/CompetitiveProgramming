def divisor(n)
  # 約数の列挙O(√n)
  res = []
  i = 1
  while i*i <= n
    if n % i == 0
      res << i
      res << n/i if i != n/i
    end
    i += 1
  end
  res
end

a,b=gets.split.map(&:to_i)
div_a = divisor(a)
div_b = divisor(b)
div_com = div_a & div_b
p div_com