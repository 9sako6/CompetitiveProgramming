s = gets.chomp
h = {}
?a.upto(?z){|c| h[c] = s.count(c)}
even = 0
odd = 0
h.each do |c, cnt|
  if cnt.odd?
    odd += 1
    even += (cnt - 1) / 2
  else
    even += cnt / 2
  end
end

p odd == 0 ? s.size : even / odd * 2 + 1
