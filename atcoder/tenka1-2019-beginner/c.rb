n = gets.to_i
a = n.times.map { gets.to_i }
score = 0
more = a.sort.reverse
less = a.sort
ans = []
i = 0
op_more = 0 # 0のとき左から
op_less = 0 # 0のとき左から
cnt = (n % 2 == 0 ? n : n - 1)
while i < cnt
  if i % 2 == 0
    if op_less == 0
      ans.unshift(less.shift)
    else
      ans.push(less.shift)
    end
    op_less = 1 - op_less
  else
    if op_more == 1
      ans.unshift(more.shift)
    else
      ans.push(more.shift)
    end
    op_more = 1 - op_more
  end
  i += 1
end
if n % 2 == 0
  p ans.each_cons(2).map { |(x, y)| (x - y).abs }.inject(:+)
else
  cands = [ans.dup, ans.dup]
  cands[0].push(more[0])
  cands[1].unshift(more[0])
  p cands.map { |cand| cand.each_cons(2).map { |(x, y)| (x - y).abs }.inject(:+) }.max
end
