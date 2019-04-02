n = gets.to_i
s = gets.chomp
if s.size.odd?
  puts "No"
  exit
end

if s[0...s.size/2] == s[s.size/2..-1]
  puts "Yes"
else
  puts "No"
end