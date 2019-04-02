N = gets.to_i
A = gets.split.map(&:to_i)
A.sort!
plus, minus = A.partition { |i| i >= 0 }
if minus.size == 0
  puts plus.inject(:+) - plus[0] * 2
  temp = plus.shift
  while plus.size > 1
    a = plus.shift
    puts "#{temp} #{a}"
    temp -= a
  end
  a = plus.pop
  puts "#{a} #{temp}"
  temp = a - temp
elsif plus.size == 0
  puts -minus.inject(:+) + minus[-1] * 2
  temp = minus.pop
  while minus.size > 0
    a = minus.shift
    puts "#{temp} #{a}"
    temp -= a
  end
else
  puts plus.inject(:+) - minus.inject(:+)
  temp = minus.pop
  while plus.size > 1
    a = plus.pop
    puts "#{temp} #{a}"
    temp -= a
  end
  a = plus.pop
  puts "#{a} #{temp}"
  temp = a - temp
  while minus.size > 0
    a = minus.shift
    puts "#{temp} #{a}"
    temp -= a
  end
end
