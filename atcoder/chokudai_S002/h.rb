N=gets.to_i
ans = []
N.times do
  a,b = gets.split.map(&:to_i)
  if a == b
    ans << -1
  else
    ans << (a-b).abs
  end
end
puts ans