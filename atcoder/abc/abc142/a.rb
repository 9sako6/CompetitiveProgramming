n = gets.to_i
if n.odd?
  puts sprintf("%.10f", ((n / 2 + 1) / n.to_f))
else
  puts sprintf("%.10f", ((n / 2) / n.to_f))
end
