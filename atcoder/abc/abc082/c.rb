N = gets.to_i
a = gets.split.map(&:to_i)

cnt = Hash.new(0)
ans = 0

a.each do |ai|
  cnt[ai] += 1
end
cnt.each do |k,v|
  if k > v
    ans += v
  elsif v > k
    ans += v-k
  end
end

puts ans