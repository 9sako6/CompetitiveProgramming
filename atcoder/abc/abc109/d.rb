H,W = gets.split.map(&:to_i)
a = []
H.times do
  a << gets.split.map(&:to_i)
end

ans = []

(H-1).times do |h|
  W.times do |w|
    if a[h][w].odd?
      a[h+1][w] += 1
      ans << [h+1,w+1, h+1+1, w+1] * ' '
    end
  end
end

(W-1).times do |w|
  if a[H-1][w].odd?
    a[H-1][w+1] += 1
    ans << [H, w+1, H, w+1+1] * ' '
  end
end

puts ans.size
puts ans
