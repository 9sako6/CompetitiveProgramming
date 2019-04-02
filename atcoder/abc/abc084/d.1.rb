def prime?(n)
  (2..(n**(0.5)).to_i).each do |i|
    return false if n % i == 0
  end
  return n > 1
end
Q=gets.to_i
max = 10**5 + 10
a = Array.new(max, 0)

max.times do |i|
  a[i] = 1 if prime?(i) && prime?((i+1)/2)
end
s = Array.new(max+1, 0)
max.times do |i|
  s[i+1] = s[i] + a[i]
end
ans = []
Q.times do
  l, r = gets.split.map(&:to_i)
  r += 1
  ans << s[r] - s[l]
end

puts ans

