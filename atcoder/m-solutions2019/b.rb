s=gets.chomp
puts (15 - s.size + s.count('o') >= 8 ? 'YES' : 'NO')
