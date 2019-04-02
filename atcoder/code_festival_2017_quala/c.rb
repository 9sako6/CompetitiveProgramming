h, w = gets.split.map(&:to_i)
a = h.times.map { gets.chomp }
s = a.join("")
cnt = {}
?a.upto(?z) { |c| cnt[c] = s.count(c) }

if w == 1
  if h.odd?
    puts cnt.values.select { |x| x.odd? }.size == 1 ? "Yes" : "No"
  else
    puts cnt.values.select { |x| x.odd? }.size == 0 ? "Yes" : "No"
  end
else
  if h.even? && w.even?
    puts cnt.values.select { |x| x % 4 != 0 }.size == 0 ? "Yes" : "No"
  elsif h.odd? && w.odd?
    ume = 0
    ?a.upto(?z) do |c|
      if cnt[c] >= 4 && (h - 1) * (w - 1) > ume
        ume += (cnt[c] / 4) * 4
        cnt[c] -= (cnt[c] / 4) * 4
        if (h - 1) * (w - 1) < ume
          cnt[c] += ume - (h - 1) * (w - 1)
          ume = (h - 1) * (w - 1)
        end
      end
    end
    if ume != (h - 1) * (w - 1)
      puts "No"
      exit
    end
    puts cnt.values.select { |x| x.odd? }.size == 1 ? "Yes" : "No"
  else
    ume = 0
    t = h.odd? ? w : h
    ?a.upto(?z) do |c|
      if cnt[c] >= 4 && h * w - t > ume
        ume += (cnt[c] / 4) * 4
        cnt[c] -= (cnt[c] / 4) * 4
        if h * w - t < ume
          cnt[c] += ume - h * w - t
          ume = h * w - t
        end
      end
    end
    if ume != h * w - t
      puts "No"
      exit
    end
    puts cnt.values.select { |x| x.odd? }.size == 0 ? "Yes" : "No"
  end
end
