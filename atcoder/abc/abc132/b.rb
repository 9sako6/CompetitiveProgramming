n=gets.to_i
P=gets.split.map(&:to_i)
cnt = 0
(1...(n-1)).each do |i|
  if P[i-1] < P[i] && P[i+1] > P[i]
    cnt += 1
  elsif  P[i-1] > P[i] && P[i+1] < P[i]
    cnt += 1
  end
end
p cnt