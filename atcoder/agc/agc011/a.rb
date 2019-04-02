n, c, k = gets.split.map(&:to_i)
t = n.times.map { gets.to_i }.sort

ans = 0
j = 0
cnt = 1
1.upto(n-1) do |i|
  if k >= t[i] - t[j] && c > cnt
    cnt += 1
  else
    cnt = 1
    ans += 1
    j = i
  end
end
p ans + 1