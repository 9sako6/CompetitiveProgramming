n=gets.not_nil!.to_i
max = 0
ans = 1
(1..n).each do |i|
    cnt = 0
    t = i
    while t.even? && t > 0
        t /= 2
        cnt += 1
    end
    if max < cnt
        ans = i
        max = cnt
    end
end
puts ans