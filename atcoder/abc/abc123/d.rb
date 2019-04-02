*_, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i).sort.reverse
b = gets.split.map(&:to_i).sort.reverse
c = gets.split.map(&:to_i).sort.reverse
puts a.product(b).map { |x, y| x + y }.sort.reverse[0, k].product(c).map{ |x, y| x + y }.sort.reverse[0, k]
# require "benchmark"
# arr = [*0...20000000].shuffle
# Benchmark.bm(12) do |x|
#   x.report("sort".ljust(12)) { arr.sort { |x, y| y <=> x } }
#   x.report("sort_by".ljust(12)) { arr.sort_by { |x| -x } }
#   x.report("sort.reverse".ljust(12)) { arr.sort.reverse }
# end
