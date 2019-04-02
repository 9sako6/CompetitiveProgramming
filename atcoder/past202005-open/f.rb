n = gets.to_i
a = n.times.map { gets.chomp }
foward = []
mid = n.odd? ? [a[n / 2][0]] : []
back = []

(n / 2).times do |i|
  j = n - 1 - i
  h = {}
  'a'.upto('z') { |c| h[c] = a[i].count(c) }
  continue_flag = false
  a[j].each_char do |c|
    if h[c] > 0
      foward.push(c)
      back.unshift(c)
      continue_flag = true
    end
  end
  if !continue_flag
    p -1
    exit
  end
end

puts (foward + mid + back).join
