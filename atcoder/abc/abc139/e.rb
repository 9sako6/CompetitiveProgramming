n = gets.to_i
a = []
n.times do |i|
  a << gets.split.map { |x| x.to_i - 1 }
end
day = 0

done = (1 << n) - 1

loop do
  cnt = 0
  players = (1 << n) - 1
  n.times do |i|
    break if players == 0
    if players[i] == 1
      if a[i].empty?
        done ^= (1 << i) if done[i] == 1
        next
      end
      j = a[i][0]
      if j && a[j][0] == i && players[j] == 1
        a[i].shift
        a[j].shift
        players ^= (1 << i)
        players ^= (1 << j)
        cnt += 1
        done ^= (1 << i) if a[i].empty? && done[i] == 1
        done ^= (1 << j) if a[j].empty? && done[j] == 1
      end
    end
  end
  if cnt == 0
    puts -1
    exit
  end
  day += 1

  if done == 0
    puts day
    exit
  end
end
