n = gets.to_i
s = gets.chomp
ans = 0
cnt = 0
s.chars do |c|
    cnt += c == "I" ? 1 : -1
    ans = [ans, cnt].max
end
p ans
