n, t = gets.split.map(&:to_i)
q = []
ans = []
now = 0
n.times do
  a, b = gets.split
  b = b.to_i
  if b <= t
    ans << [a, b + now]
    now += b
  else
    q << [a, b - t]
    now += t
  end
end
until q.empty?
  a, b = q.shift
  if b <= t
    ans << [a, b + now]
    now += b
  else
    q << [a, b - t]
    now += t
  end
end

puts ans.map { |(a, b)| "#{a} #{b}" }
