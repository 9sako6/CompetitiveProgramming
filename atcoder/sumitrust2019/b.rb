n = gets.to_i
50500.times do |x|
  if n == (x * 1.08).to_i
    puts x
    exit
  end
end
puts ":("