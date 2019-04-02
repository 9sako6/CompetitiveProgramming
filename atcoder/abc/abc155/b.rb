n = gets.to_i
a = gets.split.map(&:to_i)
a.each do |ai|
  if ai.even?
    if !((ai % 3 == 0) || (ai % 5 == 0))
      puts "DENIED"
      exit
    end
  end
end
puts "APPROVED"