s = gets.chomp.gsub!("BC", "D")
if s.nil?
  puts 0
  exit
end
ans = 0
cntA = 0
s.chars do |c|
  if c == "A"
    cntA += 1
  elsif c == "D"
    ans += cntA
  else
    cntA = 0
  end
end
p ans