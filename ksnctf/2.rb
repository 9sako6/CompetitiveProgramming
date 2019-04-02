s = gets.chomp
ans = ""
s.chars do |c|
  if ('A' <= c && c <= 'Z')
    p c.ord
    ans << ('A'.ord + (c.ord - 'A'.ord + 13)%26).chr
  elsif ('a' <= c && c <= 'z')
    ans << ('a'.ord + (c.ord - 'a'.ord+ 13)%26).chr
  else
    ans << c
  end
end
puts ans