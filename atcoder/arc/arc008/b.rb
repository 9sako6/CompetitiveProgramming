n, m = gets.split.map(&:to_i)
name = gets.chomp
kit = gets.chomp

h = {}
"A".upto("Z") { |c| h[c] = name.count(c) }
ans = -1
s = name.chars.uniq
s.each do |c|
  if kit.count(c) == 0
    puts -1
    exit
  end
  ans = [ans, (h[c] / kit.count(c).to_f).ceil].max
end

puts ans
