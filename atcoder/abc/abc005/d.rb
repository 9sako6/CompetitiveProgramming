n = gets.to_i
d = n.times.map { gets.split.map(&:to_i) }

s = Array.new(n + 1) { Array.new(n + 1, 0) }
n.times do |i|
  si = s[i]
  si1 = s[i + 1]
  di = d[i]
  n.times do |j|
    si1[j + 1] = si[j + 1] + si1[j] - si[j] + di[j]
  end
end
q = gets.to_i
ans = Array.new(n * n + 1, 0)
1.upto(n * n) do |tako|
  score = 0
  n.times do |i|
    si = s[i]
    1.upto(n) do |h|
      next if i + h >= n + 1
      next if tako % h != 0
      sih = s[i + h]
      w = tako / h
      n.times do |j|
        now_score = 0
        next if j + w >= n + 1
        now_score = sih[j + w] - si[j + w] - sih[j] + si[j]
        score = now_score if now_score > score
      end
    end
  end
  ans[tako] = score
end

ans.each_with_index do |a, i|
  next if i == 0
  if a < ans[i - 1]
    ans[i] = ans[i - 1]
  end
end

output = []
q.times do
  output << ans[gets.to_i]
end
puts output
