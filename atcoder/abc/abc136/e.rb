n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

sum = a.inject(&:+)
divs = []
t = 1
while t * t <= sum
  if sum % t == 0
    divs << t
    divs << sum / t if sum / t != t
  end
  t += 1
end
divs.sort!.reverse!
divs.each do |d|
  r = a.map { |ai| ai % d }
  r.sort!
  sumr = [tmp = 0].concat(r.map { |ri| tmp += ri })
  rdiff = r.map { |ri| d - ri }
  sumrd = [tmp = 0].concat(rdiff.map { |ri| tmp += ri })
  n.times do |i|
    if k >= sumr[i] - sumr[0] && sumr[i] - sumr[0] == sumrd[n] - sumrd[i]
      puts d
      exit
    end
  end
end
puts 1