def fin(message = "")
  puts "NG #{message.inspect}"
  exit
end

n = gets.to_i
s = n.times.map { gets.split.map(&:to_i) }
ok = true
cnt = Hash.new(0)

s.each do |si|
  si.map { |sij| cnt[sij] += 1 }
end
1.upto(n) do |i|
  ok = false if cnt[i] != 2
  fin([i, cnt]) unless ok
end

n.times do |i|
  ((i + 1)...n).each do |j|
    ok = false if (s[i] & s[j]).size != 1
    fin((s[i] & s[j])) unless ok
  end
end

puts "OK" if ok
