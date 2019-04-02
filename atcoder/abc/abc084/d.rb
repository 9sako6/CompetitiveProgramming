def prime?(n)
  return n >= 2 if n <= 3
  return true if n == 5
  return false unless 30.gcd(n) == 1
  (7..n**(0.5)).step(30) do |p|
    return false if
      n % (p) == 0 || n % (p + 4) == 0 || n % (p + 6) == 0 || n % (p + 10) == 0 ||
      n % (p + 12) == 0 || n % (p + 16) == 0 || n % (p + 22) == 0 || n % (p + 24) == 0
  end
  true
end

Q = gets.to_i
max = 10**5+10

a = Array.new(max, 0)
max.times do |i|
  if prime?(i) && prime?((i+1)/2)
    a[i] = 1
  end
end

s = Array.new(max+1, 0)
max.times do |i|
  s[i+1] = s[i] + a[i]
end

ans = []
Q.times do
  l, r = gets.split.map(&:to_i)
  ans << s[r+1] - s[l]
end
puts ans
