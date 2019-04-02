s = gets.chomp
s.gsub!(/ch|[oku]/, "")
puts s.size == 0 ? "YES" : "NO"
