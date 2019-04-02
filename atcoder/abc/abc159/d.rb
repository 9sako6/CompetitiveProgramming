n = gets.to_i
a = gets.split.map(&:to_i)
cnt = Hash.new(0)
a.map { |ai| cnt[ai] += 1 }
all = 0
cnt.each do |k, v|
  all += v * (v - 1) / 2
end
n.times do |i|
  p all - (cnt[a[i]] - 1)
end