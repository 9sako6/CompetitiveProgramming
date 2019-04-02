Q, L = gets.split.map(&:to_i)
stack = []
s = 0
Q.times do
  query, n, m = gets.split
  n = n.to_i
  m = m.to_i

  case query
  when 'Push'
    if L < s + n
      puts 'FULL'; exit
    end
    stack << [n, m]
    s += n
  when 'Pop'

    while n > 0
      if stack.empty?
        puts 'EMPTY'; exit
      end
      ntop, mtop = stack.pop
      if ntop > n
        stack << [ntop - n, mtop]
        s -= n
      else
        s -= ntop
      end
      n -= ntop
    end
  when 'Top'
    if stack.empty?
      puts 'EMPTY'; exit
    end
    puts stack[-1][1]
  when 'Size'
    puts s
  end
end

puts 'SAFE'
