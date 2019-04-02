n, m = gets.split.map(&:to_i)
g = Array.new(n){Array.new(n, false)}
m.times do
    x, y = gets.split.map(&:to_i)
    g[x-1][y-1] = g[y-1][x-1] = true
end

ans = 0
(1<<n).times do |s|
    ok = true
    n.times do |i|
        i.times do |j|
            if s[i] == 1 && s[j] == 1 && !g[i][j]
                ok = false
            end
        end
    end
    ans = [s.to_s(2).count("1"), ans].max if ok
end
p ans