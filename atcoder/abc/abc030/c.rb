n, m = gets.split.map(&:to_i)
x, y = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
ans = 0
ta = a[0]
while true
  # A to B
  sa = a.bsearch { |ai| ta <= ai }
  break if !sa
  tb = sa + x
  sb = b.bsearch { |bi| tb <= bi }
  break if !sb
  ta = sb + y
  ans += 1
end
p ans
