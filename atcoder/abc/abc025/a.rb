s = gets.chomp.chars
n = gets.to_i
cands = []
s.each do |c1|
  s.each do |c2|
    cands << c1 + c2
  end
end
puts cands.sort[n-1]