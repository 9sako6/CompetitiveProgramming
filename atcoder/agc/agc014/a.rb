a,b,c=gets.split.map(&:to_i)
if a==b && b==c && a.even?
  puts -1
  exit(0)
elsif a==b && b==c && a.odd?
  puts 0
  exit(0)
end
ans = 0
while a.even? && b.even? && c.even?
  _a, _b, _c = a,b,c
  a = (_b+_c)/2
  b = (_a+_c)/2
  c = (_a+_b)/2
  ans += 1
end
p ans


