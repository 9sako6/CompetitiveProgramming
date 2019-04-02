n, k = gets.split.map(&:to_i)
sushi = Hash.new { |h, k| h[k] = [] }

s_0 = []
s_1 = []

n.times do
  t, d = gets.split.map(&:to_i)
  sushi[t] << d
end
sushi.values.each do |arr|
  arr.sort!.reverse!
  arr.each_with_index do |a, i|
    if i == 0
      s_1 << a
    else
      s_0 << a
    end
  end
end
s_0.sort!.reverse!
s_1.sort!.reverse!

n_0 = s_0.size
n_1 = s_1.size

# 累積和
sum_0 = [tmp = 0].concat(s_0.map { |si| tmp += si })
sum_1 = [tmp = 0].concat(s_1.map { |si| tmp += si })

ans = 0
(k + 1).times do |i|
  next if i == 0
  # s_1 からi個とる
  x = i
  y = k - i
  # 取れないときのための微調整
  if x > n_1
    y += x - n_1
    x = n_1
  end
  if y > n_0
    x += y - n_0
    y = n_0
  end
  sum = sum_1[x] + sum_0[y] + x * x
  ans = sum if sum > ans
end

p ans

