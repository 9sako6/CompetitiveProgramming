$n = gets.to_i

def solve(str)
  ((str.size == $n) ?
    (puts str) :
    ("abc".chars.map { |c| solve(str + c) }))
end

solve("")
