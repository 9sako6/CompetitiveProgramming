def solve(n)
  # 約数の列挙O(√n)
  ans = 1e13
  i = 1
  while i * i <= n
    if n % i == 0
      # res << i
      # res << n/i if i != n/i
      ans = [ans, i + n / i].min
    end
    i += 1
  end
  ans
end

n = gets.to_i

p solve(n) - 2
