b=[]
19.times do
  b << gets.chomp
end
# 手数
num_o = 0
num_x = 0
19.times do |i|
  19.times do |j|
    num_o += 1 if b[i][j] == 'o'
    num_x += 1 if b[i][j] == 'x'
  end
end
if num_x > num_o
  puts 'NO'
  exit(0)
end