def prime?(num)
  return false if num < 2
  return true if num == 2
  (2..(num**(0.5))).each do |i|
    return false if num % i == 0
  end
  return true
end

N=gets.to_i
ans = [11]
num = 11
while ans.size < N
  num += 5 
  next if !(prime?(num))
  ans << num
end

puts ans * ' '

