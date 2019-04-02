n = gets.to_i
a = gets.split.map(&:to_i).sort.reverse
i = -1
x, y = a.partition { |ai| i += 1; i.even? }.map { |arr| arr.inject(&:+) }
p x - y
