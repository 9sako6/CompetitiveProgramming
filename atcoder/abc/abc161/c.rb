n, k = gets.split.map(&:to_i)
if n >= k
  m = (n + k - 1) / k * k
  puts [n % k, (n - m).abs].min
else
  ans = [n, (n - k).abs].min
  puts ans
end
