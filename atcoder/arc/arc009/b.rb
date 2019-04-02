b = gets.gsub(" ", "")
puts Array.new(gets.to_i) { gets.chomp }.sort_by { |a| a.tr(b, "0123456789").to_i }
