n = gets.to_i
s = 5.times.map { gets.chomp }
ans = ""
n.times do |i|
  start_col = i * 4
  end_col = start_col + 3
  if s[2][end_col - 1] == '.'
    ans << ( s[2][end_col - 2] == '.' ? '7' : '0')
  elsif s[0][end_col-1] == '.'
    ans << '4'
  elsif s[0][start_col + 1] == '.'
    ans << '1'
  elsif s[1][start_col + 1] == '.' 
    ans << (s[3][start_col + 1] == '.' ? '3' : '2')
  elsif s[3][start_col + 1] == '.'
    ans << (s[1][end_col] == '.' ? '5' : '9')
  else
    ans << (s[1][end_col] == '.' ? '6' : '8')
  end
end

puts ans
