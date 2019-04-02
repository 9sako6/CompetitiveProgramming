m,d=gets.split.map(&:to_i)
ans = 0
(1..m).each do |mo|
  (1..d).each do |da|
    next if da < 10
    d1, d2 = da.to_s.split('').map(&:to_i)
    next if d1 < 2
    next if d2 < 2
    ans += 1 if d1*d2 == mo
  end
end
p ans
