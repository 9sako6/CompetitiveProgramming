require "numo/narray"
include Numo
n, q = gets.split.map(&:to_i)
a = Int32[*gets.split.map(&:to_i)]
s = gets.split.map(&:to_i)
# 1.upto(n - 1) do |i|
#   a[i] = a[i].gcd(a[i - 1])
# end
p a.cumsum(&:gcd)
# q.times do |i|
#   ng = -1
#   ok = n
#   while (ng - ok).abs > 1
#     mid = (ok + ng) / 2
#     if a[mid].gcd(s[i]) == 1
#       ok = mid
#     else
#       ng = mid
#     end
#   end
#   if ok == n
#     p a[-1].gcd(s[i])
#   else
#     p ok + 1
#   end
# end
