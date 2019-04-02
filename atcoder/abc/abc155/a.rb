a = gets.split.map(&:to_i).uniq
puts a.size == 2 ? "Yes" : "No"

