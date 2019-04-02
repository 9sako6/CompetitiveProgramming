N,X=gets.split.map(&:to_i)
ls=gets.split.map(&:to_i)
ans = 1
prev = 0
ls.each do |l|
  prev += l
  if prev <= X
    ans += 1
  else
    break
  end
end
p ans
