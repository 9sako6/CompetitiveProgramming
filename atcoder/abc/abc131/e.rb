N, K = gets.split.map(&:to_i)
if K > (N - 1) * (N - 2) / 2
  p -1
  exit
end
ans = []
2.upto(N) do |i|
  ans << "1 #{i}"
end
cnt = 0
from = 2
to = 3
while cnt < (N - 1) * (N - 2) / 2 - K
  ans << "#{from} #{to}"
  cnt += 1
  if to >= N
    from += 1
    to = from + 1
  else
    to += 1
  end
end
puts ans.size
puts ans
