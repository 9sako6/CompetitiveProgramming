k, n = gets.split.map(&:to_i)
a = gets.split.map(&:to_i).sort
ans = 10 ** 9

n.times do |start|
  goal = start == 0 ? n - 1 : start - 1
  tmp = k - (a[start] - a[goal]).abs
  tmp = a[goal] - a[start] if start == 0
  ans = tmp if ans > tmp
  # p [start, goal, tmp]
end
p ans