n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

s = a.inject(&:+)
divs = []
i = 1
while i * i <= s
  if s % i == 0
    divs << i
    divs << s / i if s / i != i
  end
  i += 1
end
ans = []
divs.sort.reverse.each do |d|
  r = a.map { |x| x % d }.sort
  if r.all? { |x| x == 0 }
    puts d
    exit
  end
  sum = 0
  negs = [0].concat(r.map { |x| sum += x })
  sum = 0
  1.upto(n - 1) do |j|
    negop = negs[j] - negs[0]
    posop = ((n - j) * d - (negs[n] - negs[j]))
    if (negop == posop && negop <= k)
      puts d
      exit
    end
  end
end
p 1
