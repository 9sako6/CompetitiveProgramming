S = gets.chomp
def even?(str)
  return str[0...str.size/2] == str[str.size/2..-1]
end
new_s = S
while true
  new_s = new_s[0...-1]
  if even?(new_s)
    puts new_s.size
    break
  end
end