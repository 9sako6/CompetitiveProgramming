n, d, k = gets.split.map(&:to_i)
l, r = d.times.map { gets.split.map(&:to_i) }.transpose
s, t = k.times.map { gets.split.map(&:to_i) }.transpose

ans = Array.new(k)

k.times do |ki|
  now = s[ki]
  d.times do |di|
    if l[di] <= now && now <= r[di]
      if s[ki] <= t[ki]
        now = r[di]
        if now >= t[ki]
          ans[ki] = di + 1
          break
        end
      else
        now = l[di]
        if now <= t[ki]
          ans[ki] = di + 1
          break
        end
      end
    end
  end
end

puts ans
