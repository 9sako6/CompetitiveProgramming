a, r, n = gets.split.map(&:to_i)
if Math.log10(a) + Math.log10(r) * (n - 1) > 9
  puts 'large'
else
  ans =  a * (r**(n - 1))
  if ans > (10 ** 9)
    puts 'large'
  else
    puts ans
  end
end
