n, m = gets.split.map(&:to_i)
s, c = m.times.map { gets.split.map(&:to_i) }.transpose

num = Array.new(n, nil)

m.times do |i|
  tmp = num[s[i] - 1]
  if tmp && tmp != c[i] # すでに違う数が決まっている
    puts "-1"
    exit
  end
  num[s[i] - 1] = c[i]
end

# 0は1桁の整数
if n == 1 && num[0] == 0
  puts 0
  exit
end
# 先頭の0連続する0消す
while num[0] == 0
  num.shift
end
if num.size != n
  puts "-1"
  exit
end
if num[0] == nil && n == 1
  puts 0
  exit
elsif num[0] == nil
  num[0] = 1
end
num.map! { |x| x == nil ? 0 : x }
puts num * ""
