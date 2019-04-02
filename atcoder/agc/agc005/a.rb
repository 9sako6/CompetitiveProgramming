x = gets.chomp
s = []
x.chars do |c|
  if c == "s"
    s << c
  elsif c == "T" && s[-1] == "S"
    s.pop
  else
    s << c
  end
end

p s.size
