a = gets.chomp
k = gets.to_i
n = a.size
if n < k
  puts 0
  exit
end

i = 0
cands = []
while i +k <= n
  cands << a[i...i+k]
  i += 1
end
p cands.uniq.size

