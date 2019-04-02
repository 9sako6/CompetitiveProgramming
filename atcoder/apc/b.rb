n = gets.to_i
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)

diff = b.inject(&:+) - a.inject(&:+)
cnt_a = cnt_b = 0
a.zip(b).each do |ai, bi|
  if ai < bi
    cnt_a += (bi - ai + 1) / 2
  else
    cnt_b += (ai - bi)
  end
end
puts ((diff >= 0) && (diff >= [cnt_a, cnt_b].max)) ? "Yes" : "No"
