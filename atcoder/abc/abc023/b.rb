n = gets
s = gets.chomp

a = []
110.times do |i|
  case i % 3
  when 0
    if i == 0
      a << 'b'
    else
      a.unshift('b')
      a << 'b'
    end
  when 1
    a.unshift('a')
    a << 'c'
  when 2
    a.unshift('c')
    a << 'a'
  end
  if a.join("") == s
    puts i
    exit
  end
end

puts -1
