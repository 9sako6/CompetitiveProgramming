n = gets.to_i
x, y = n.times.map{gets.split.map(&:to_i)}.transpose
k = 1

n.times do |i|
  k *= i+1
end
sum = 0
[*0...n].permutation(n) do |arr|
  arr.each_cons(2) do |a, b|
    t = (((x[a] - x[b])**2) + ((y[a] - y[b])**2))**(0.5)
    sum += t
  end
end
p sum / k.to_f
