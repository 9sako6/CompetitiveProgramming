n=gets
h=gets.split.map(&:to_i)
h.reverse!
(h.size-1).times do |i|
  if h[i] >= h[i+1]
    next
  else
    h[i+1] -= 1
    if h[i] >= h[i+1]
      next
    else
      puts "No"
      exit
    end
  end
end

puts "Yes"