N, M = gets.split.map(&:to_i)
A = gets.split.map(&:to_i)
 
sum_mod = [0]
A.each_with_index do |a, idx|
  sum_mod[idx + 1] = (sum_mod[idx] + a) % M
end
 
count = Hash.new(0)
ans = 0
sum_mod.each do |sm|
  ans += count[sm]
  count[sm] += 1
end
p count
puts ans