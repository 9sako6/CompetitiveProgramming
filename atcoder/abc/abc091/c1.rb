N=gets.to_i
red = []
blue = []
ans = 0
N.times do
  red << gets.split.map(&:to_i)
end
N.times do
  blue << gets.split.map(&:to_i)
end

blue.sort_by!{|pos| pos[0]}
red.sort_by!{|pos| -pos[1]}
ans = 0
blue.each do |b|
  red.each do |a|
    if b[0] > a[0] && b[1] > a[1]
      red.delete(a)
      ans += 1
      break
    end
  end
end
puts ans