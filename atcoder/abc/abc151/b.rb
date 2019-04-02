n, k, m = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
suma = a.inject(&:+)
(k+1).times do |score|
  if suma + score >= n * m
    puts score <= k ? score : -1
    exit
  end
end
puts -1
# puts ans <= k ? ans : -1