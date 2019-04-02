a = gets.to_i
b = gets.to_i
c = gets.to_i
x = gets.to_i
ans = 0
0.upto(a) do |s|
  0.upto(b) do |t|
    0.upto(c) do |u|
      ans += 1 if s * 500 + t * 100 + u * 50 == x
    end
  end
end
p ans