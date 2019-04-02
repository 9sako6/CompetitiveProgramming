require "numo/narray"
include Numo
n = gets.to_i
red = Int32[]
blue = Int32[]
n.times do
  x, c = gets.split
  x = x.to_i
  if c == "R"
    red << x
  else
    blue << x
  end
end

puts red.sort
puts blue.sort
