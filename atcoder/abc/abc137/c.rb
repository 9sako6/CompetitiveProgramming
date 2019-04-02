n = gets.to_i
cnt = Hash.new(0)
n.times do
  si = gets.chomp.chars.sort.join('')
  cnt[si] += 1
end
ans = 0
cnt.each do |k,v|
  next if v == 1
  ans += v*(v-1)/2
end
p ans

