n = gets.to_f
arr = [*1..9]
flag = false
(1..9).each do |i| 
  if arr.include?(n / i )
    flag = true
  end
end

puts flag ? "Yes" : "No"
  