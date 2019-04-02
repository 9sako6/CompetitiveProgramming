n, m = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

memo = Array.new(n, -1)

a.each do |sushi|
  i = memo.bsearch_index{|x| x < sushi}
  puts i.nil? ? -1 : i + 1
  memo[i] = sushi unless i.nil?
end
