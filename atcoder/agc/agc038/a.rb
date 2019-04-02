h, w, a, b = gets.split.map(&:to_i)
if a > w / 2 || b > h / 2
  puts "No"
  exit
end

ans = Array.new(h) { Array.new(w, 0) }
b.times do |i|
  a.times do |j|
    ans[i][j] = 1
  end
end
(b...h).each do |i|
  (a...w).each do |j|
    ans[i][j] = 1
  end
end

puts ans.map{|x| x * ""}