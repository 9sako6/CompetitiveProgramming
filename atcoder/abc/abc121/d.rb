def fd(n)
  cnt = ((n+1) / 2)
  if n % 2 == 0
    return cnt % 2 == 0 ? n : (1 ^ n)
  else
    return cnt % 2 == 0 ? 0 : 1
  end
end
a, b = gets.split.map(&:to_i)
puts fd(a-1) ^ fd(b)