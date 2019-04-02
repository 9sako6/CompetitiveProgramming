N = gets.to_i
a = gets.split.map(&:to_i)
cnt = [0,0]
2.times do |j|
    sign = -2*j+1
    sum = 0
    N.times do |i|
        sum += a[i]
        if sign == -1 && sum >= 0
            cnt[j] += 1+sum
            sum = -1
        elsif sign == 1 && sum <= 0
            cnt[j] += 1 - sum
            sum = 1
        end
        sign *= -1
    end
end
puts cnt.min

