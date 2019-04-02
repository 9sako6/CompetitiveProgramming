s = gets.chomp
ans = []
tmp = ""
s.each_char.with_index do |c, i|
  if i == 0
    ans << c
  else
    if tmp + c == ans[-1]
      tmp << c
    elsif tmp.size > 0
      tmp << c
      ans << tmp
      tmp = ""
    else
      ans << c
    end
  end
end

p ans.size
