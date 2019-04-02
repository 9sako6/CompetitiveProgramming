n, m, k = gets.split.map(&:to_i)
(n + 1).times do |r|
  (m + 1).times do |c|
    if r * m + c * n - 2 * r * c == k
      puts "Yes"
      exit
    end
  end
end
puts "No"
