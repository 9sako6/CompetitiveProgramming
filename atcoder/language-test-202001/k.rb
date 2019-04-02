n = gets.to_i
t, x, y = n.times.map { gets.split.map(&:to_i) }.transpose
nowx, nowy = 0, 0
nowt = 0
n.times do |i|
  d = (nowx - x[i]).abs + (nowy - y[i]).abs
  if (t[i] - nowt) < d
    puts "No"
    exit
  else
    unless ((t[i] - nowt).even? && d.even?) || ((t[i] - nowt).odd? && d.odd?)
      puts "No"
      exit
    end
  end
  nowx, nowy = x[i], y[i]
  nowt = t[i]
end

puts "Yes"
