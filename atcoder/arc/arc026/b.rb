def divs(n)
  res = []
  i = 1
  while i * i <= n
    if n % i == 0
      res << i
      res << n / i if i != n / i
    end
    i += 1
  end
  res
end

n = gets.to_i
s = divs(n).map { |x| x == n ? 0 : x }.inject(&:+)
puts (n == s ? "Perfect" : (n > s ? "Deficient" : "Abundant"))
