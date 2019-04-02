s = gets.chomp
h = {}
"a".upto("c") { |c| h[c] = s.count(c) }
t = h.values.sort
if t[0] == t[1] && t[1] == t[2]
  puts "YES"
elsif t[0] == t[1] && t[2] == t[0] + 1
  puts "YES"
elsif t[0] == t[1] - 1 && t[1] == t[2]
  puts "YES"
else
  puts "NO"
end