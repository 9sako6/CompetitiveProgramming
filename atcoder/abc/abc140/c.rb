n=gets.to_i
b=gets.split.map(&:to_i)
a = Array.new(n)
(n-1).times do |i|
  if a[i].nil?
    a[i] = b[i]
  elsif a[i] > b[i]
    a[i] = b[i]
  else
    a[i] = a[i]
  end
  a[i+1] = b[i]
end
p a.inject(:+)