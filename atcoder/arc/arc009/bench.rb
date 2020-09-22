require 'benchmark'

puts RUBY_VERSION

arr = 1_000_000.times.map { rand(1000) }
# p arr
Benchmark.bm do |r|
  r.report '(n & 1) == 1' do
    arr.select { (_1 & 1) == 1 }
  end
  r.report 'Integer#odd?' do
    arr.select { _1.odd? }
  end
end

# .odd

# (n & 1) == 1
