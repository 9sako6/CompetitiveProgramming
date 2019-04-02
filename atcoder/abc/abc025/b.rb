n, a, b = gets.split.map(&:to_i)
s,d = n.times.map{gets.split}.transpose
d.map!(&:to_i)
pos = 0

def move(d, a, b) d < a ? a : (d > b ? b : d) end
n.times do |i|
  if s[i] == "East"
    pos += move(d[i], a, b)
  else
    pos -= move(d[i], a, b)
  end
end

if pos < 0
  puts "West #{pos.abs}"
elsif pos > 0
  puts "East #{pos}"
else
  puts pos
end
