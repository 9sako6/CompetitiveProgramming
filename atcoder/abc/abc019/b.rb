s = gets.chomp
ans = ""
prev = "#"
cnt = 1
s.chars do |c|
  if prev == c
    cnt += 1
  else
    ans << "#{prev}#{cnt}"
    cnt = 1
    prev = c
  end
end
ans << "#{prev}#{cnt}"
puts ans[2..-1]
