m = gets.to_i

d, c = m.times.map { gets.split.map(&:to_i) }.transpose

debug = true
if debug
  real_num = ""
  m.times do |i|
    real_num << "#{d[i]}" * c[i]
  end
  p real_num
end

# 同じ数字が10並んでいる列に操作をすると、10回操作した後、元の数字1つになる
# 3333333333 -> 3 (10回)


