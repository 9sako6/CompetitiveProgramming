n = gets.to_i
ans = "second"
n.times do
  a = gets.to_i
  if a.odd?
    ans = "first"
  end
end
puts ans