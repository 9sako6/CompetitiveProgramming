n=gets.not_nil!.to_i
ans = 0
n.times do
    l,r = gets.not_nil!.split.map(&.to_i)
    ans += r-l+1
end
puts ans