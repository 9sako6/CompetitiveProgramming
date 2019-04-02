n, l = gets.split.map(&:to_i)
a = []
l.times do
  a << gets.chomp.split("|").tap { |arr| arr.shift }
end
pos = gets.chomp.chars.index("o") / 2
a.reverse.each do |row|
  if pos != 0 && row[pos - 1] == "-"
    pos -= 1
  elsif pos != n - 1 && row[pos] == "-"
    pos += 1
  end
end

p pos + 1
