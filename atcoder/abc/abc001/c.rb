deg, dis = gets.split.map(&:to_i)

deg *= 10
if deg < 1125
  dir = "N"
elsif deg < 3375
  dir = "NNE"
elsif deg < 5625
  dir = "NE"
elsif deg < 7875
  dir = "ENE"
elsif deg < 10125
  dir = "E"
elsif deg < 12375
  dir = "ESE"
elsif deg < 14625
  dir = "SE"
elsif deg < 16875
  dir = "SSE"
elsif deg < 19125
  dir = "S"
elsif deg < 21375
  dir = "SSW"
elsif deg < 23625
  dir = "SW"
elsif deg < 25875
  dir = "WSW"
elsif deg < 28125
  dir = "W"
elsif deg < 30375
  dir = "WNW"
elsif deg < 32625
  dir = "NW"
elsif deg < 34875
  dir = "NNW"
else
  dir = "N"
end

s = (dis / 60.0).round(1)
if s <= 0.2
  w = 0
elsif s <= 1.5
  w = 1
elsif s <= 3.3
  w = 2
elsif s <= 5.4
  w = 3
elsif s <= 7.9
  w = 4
elsif s <= 10.7
  w = 5
elsif s <= 13.8
  w = 6
elsif s <= 17.1
  w = 7
elsif s <= 20.7
  w = 8
elsif s <= 24.4
  w = 9
elsif s <= 28.4
  w = 10
elsif s <= 32.6
  w = 11
else
  w = 12
end

dir = "C" if w == 0

puts "#{dir} #{w}"
