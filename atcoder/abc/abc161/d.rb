k = gets.to_i

runrun = []

q = [*1..9].map(&:to_s)
cnt = 0
while cnt < 100010 && !q.empty?
  n = q.shift
  m = n[-1].to_i
  q << "#{n}#{m - 1}" if m - 1 >= 0
  q << "#{n}#{m}"
  q << "#{n}#{m + 1}" if m + 1 <= 9
  runrun << n
  cnt += 1
end
runrun.map(&:to_i).sort!
p runrun[k - 1].to_i
