n, m, q = gets.split.map(&:to_i)

scores = Array.new(m, n)

solved = Array.new(n) { [] }
ans = []
q.times do
  s = gets.split.map(&:to_i)
  if s[0] == 1
    ans << solved[s[1] - 1].inject(0) { |sum, i| sum += scores[i] }
  else
    solved[s[1] - 1] << s[2] - 1
    scores[s[2] - 1] -= 1
  end
end
puts ans
