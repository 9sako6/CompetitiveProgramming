N=gets.to_i
a=gets.split.map(&:to_i)

b = []
i = 0
while b.size < N
  if i.even?
    b.unshift(a[i])
  else
    b << a[i]
  end
  i += 1
end

puts (N.odd? ? b*' ' : b.reverse * ' ')