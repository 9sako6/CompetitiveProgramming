n = gets.to_i
a = gets.split.map(&:to_i)

sum = a.inject(&:+)
if sum % n != 0
  puts -1
  exit
end
k = sum / n
ans = 0
len = 1
now = 0
a.each_with_index do |ai, i|
  if (now + ai) % (len) == 0 && (now + ai) / (len) == k
    ans += (len - 1)
    len = 1
    now = 0
  else
    now += ai
    len += 1
  end
end
p ans
