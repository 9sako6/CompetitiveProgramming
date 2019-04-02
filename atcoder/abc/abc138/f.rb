def debug(n)
  (1..20).each do |i|
    puts "#{i}: あまり(#{i}%#{n}) #{i%n}, XOR(#{i}^#{n}) #{i^n}    #{(i%n == i^n ? "YEEEEES" : "")}"
  end
end

n = gets.to_i
debug(n)