n, m = gets.split.map(&:to_i)

isac = Array.new(n, false)
cntwa = Array.new(n, 0)
m.times do
  a, b = gets.chomp.split
  a = a.to_i - 1
  if !isac[a]
    if b == "AC"
      isac[a] = true
    else
      cntwa[a] += 1
    end
  end
end

ac = isac.count(true)
wa = 0
n.times do |i|
  if isac[i]
    wa += cntwa[i]
  end
end
puts [ac, wa] * " "
