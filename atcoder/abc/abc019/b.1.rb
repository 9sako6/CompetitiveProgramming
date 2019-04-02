s = gets.chomp + "#"
prev = "#"
cnt = 1
ans = ""
s.chars do |c|
  if c == prev
    cnt += 1
  else
    ans << "#{prev}#{cnt}"
    prev = c
    cnt = 1
  end
end

puts ans[2..-1]