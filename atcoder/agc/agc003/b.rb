n = gets.to_i
as = n.times.map { gets.to_i }

if as.count(0) == 0
  p as.inject(&:+) / 2
else
  l = 0
  ans = 0
  as.each_with_index do |ai, i|
    if ai == 0
      if i == 0
        l = 1
      else
        ans += as[l..i].inject(&:+) / 2 if !(as[l..i].empty?)
        # p as[l..i]
        l = i+1
      end
    end
  end
  ans += as[l...n].inject(&:+) / 2 if !(as[l...n].empty?)
  p ans
end
