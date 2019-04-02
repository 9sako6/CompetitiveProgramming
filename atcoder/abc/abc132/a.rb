s=gets.chomp
cnt=Hash.new(0)
s.each_char do |c|
  cnt[c] += 1
end
flag = true
# cnt.keys.each do |key|
#   if cnt[key] != 2
#     flag = false
#     break
#   end
# end
puts (cnt.keys.size == 2 && flag) ? 'Yes' : 'No'