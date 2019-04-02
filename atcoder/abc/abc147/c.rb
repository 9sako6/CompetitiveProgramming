n = gets.to_i
a = Array.new(n)
n.times do |i|
  ai = gets.to_i
  a[i] = ai.times.map { gets.split.map(&:to_i) }
end

ans = 0
(1 << n).times do |bit|
  flag = true
  n.times do |i|
    # iの証言がbitと矛盾していないか確かめる
    if bit[i] == 1
      # honest
      a[i].each do |x, y|
        flag = false if bit[x - 1] != y
      end
    end
  end
  cnt = bit.to_s(2).count("1")
  ans = cnt if flag && ans < cnt
end
p ans