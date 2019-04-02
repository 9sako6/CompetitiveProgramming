txa, tya, txb, tyb, T, V = gets.split.map(&:to_i)
n = gets.to_i
ans = false
n.times do
  x, y = gets.split.map(&:to_f)
  to_girl = ((txa - x) ** 2 + (tya - y) ** 2) ** (0.5)
  to_goal = ((txb - x) ** 2 + (tyb - y) ** 2) ** (0.5)
  ans = true if to_girl + to_goal <= T * V
end
puts (ans ? "YES" : "NO")
