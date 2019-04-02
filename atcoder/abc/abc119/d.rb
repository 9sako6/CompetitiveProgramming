A,B,Q=gets.split.map(&:to_i)
INF = 10**22
s,t=[-INF],[-INF]
ans = []
A.times do
  s << gets.to_i
end
B.times do
  t << gets.to_i
end
s << INF
t << INF
Q.times do
  x = gets.to_i
  a = s.bsearch_index{|pos| x <= pos}.to_i
  b = t.bsearch_index{|pos| x <= pos}.to_i
  res = INF
  [s[a-1], s[a]].each do |si|
    [t[b-1], t[b]].each do |ti|
      d1 = (si-x).abs + (si-ti).abs
      d2 = (ti-x).abs + (si-ti).abs
      res = d1 if d1 < res
      res = d2 if d2 < res
    end
  end
  ans << res
end
puts ans
