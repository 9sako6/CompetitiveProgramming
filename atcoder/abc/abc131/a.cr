s=gets.not_nil!
tmp=""
ans = true
s.each_char do |c|
    if tmp == c
        ans = false
    end
    tmp = c
end
puts ans ? "Good" : "Bad"
