r, c, k = gets.split.map(&:to_i)
n = gets.to_i
rc = []
row_ame = Array.new(r, 0)
col_ame = Array.new(c, 0)
n.times do |i|
  a, b = gets.split.map { |x| x.to_i - 1 }
  rc << [a, b]
  row_ame[a] += 1
  col_ame[b] += 1
end
if k > n
  puts 0
  exit
end
ame_row = Array.new(10 ** 5 + 1, 0) # ame_row[i] := i個のあめがある行の個数
ame_col = Array.new(10 ** 5 + 1, 0) # ame_col[i] := i個のあめがある列の個数
row_ame.each { |cnt| ame_row[cnt] += 1 }
col_ame.each { |cnt| ame_col[cnt] += 1 }

ans = 0

(k + 1).times do |i|
  ans += ame_row[i] * ame_col[k - i]
end

n.times do |i|
  sum = row_ame[rc[i][0]] + col_ame[rc[i][1]]
  ans -= 1 if sum == k
  ans += 1 if sum == k + 1
end

p ans
