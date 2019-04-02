def score(str)
  sr = str.split("L").reject(&:empty?).map { |x| x.count("R") - 1 }.inject(:+)
  sl = str.split("R").reject(&:empty?).map { |x| x.count("L") - 1 }.inject(:+)
  sr.to_i + sl.to_i
end

n, k = gets.split.map(&:to_i)
s = gets.chomp

if s.count("L") == n || s.count("R") == n
  puts n - 1
  exit
end

sr = s.split("L").reject(&:empty?)
sl = s.split("R").reject(&:empty?)
if sl.size > sr.size
  # L増やす
  cnt = (k > sr.size ? sr.size : k)
  cnt.times do |i|
    break if sr[i].nil?
    sr[i] = sr[i].gsub!("R", "L")
  end
elsif sl.size < sr.size
  # R増やす
  cnt = (k > sr.size ? sr.size : k)
  cnt.times do |i|
    break if sl[i].nil?
    sl[i] = sl[i].gsub!("L", "R")
  end
else
  cnt = (k > sr.size ? sr.size : k)
  if s[0] == "L"
    cnt.times do |i|
      break if sr[i].nil?
      sr[i] = sr[i].gsub!("R", "L")
    end
  else
    cnt.times do |i|
      break if sl[i].nil?
      sl[i] = sl[i].gsub!("L", "R")
    end
  end
end
ans = []
l_first = (sl.size > sr.size)
if sl.size == sr.size
  l_first = (s[0] == "L")
end
until sl.empty? && sr.empty?
  if l_first
    ans << sl.shift
    l_first = false
  else
    ans << sr.shift
    l_first = true
  end
end
p score(ans.join(""))
