n = gets.to_i
s = gets.chomp
cands = []
10.times do |i|
  10.times do |j|
    10.times do |k|
      cands << "#{i}#{j}#{k}"
    end
  end
end
# p cands

index = Array.new(10){[]}

s.each_char.with_index do |c, i|
  index[c.to_i] << i
end
cnt = index.map(&:size)
# p index
# p cnt
ans = 0
cands.each do |num|
  flag = false
  10.times do |i|
    a = num.count(i.to_s)
    if cnt[i] < a
      flag = true
      break
    end
  end
  next if flag
  a = num[0].to_i
  ai = index[a][0]
  b = num[1].to_i
  bi = index[b].bsearch{|x| x > ai}
  next if bi.nil?
  c = num[2].to_i
  ci = index[c][-1]
  next if ci <= bi
  ans += 1
end

p ans