s = gets.chomp
t = gets.chomp
n = s.size
n.times do |i|
  if s[i] == "@"
    if t[i] !~ /[atcoder@]/
      puts "You will lose"
      exit
    end
  elsif t[i] == "@"
    if s[i] !~ /[atcoder@]/
      puts "You will lose"
      exit
    end
  else
    if s[i] != t[i]
      puts "You will lose"
      exit
    end
  end
end
puts "You can win"
