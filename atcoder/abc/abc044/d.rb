n = gets.to_i
s = gets.to_i

if s > n
  puts -1
  exit
elsif s == n
  puts n + 1
  exit
end

def f(b, n)
  return 0 if n == 0
  return f(b, n / b) + (n % b)
end

ans = 1e12

(2..(n ** 0.5)).each do |b|
  ans = b if s == f(b, n) && b < ans
end

(1..(n ** 0.5)).each do |a|
  if (n - s) % a == 0 && (n - s) / a != 0
    b = (n - s) / a + 1
    ans = b if s == f(b, n) && b < ans
  end
end

p ans == 1e12 ? -1 : ans
