s = gets.chomp
puts s.gsub("eraser", "").gsub("erase", "").gsub("dreamer", "").gsub("dream", "") == "" ? "YES" : "NO"