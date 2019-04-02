n,m = gets.split.map(&:to_i)
xyz = []
n.times do |i|
  xyz << gets.split.map(&:to_i)
end

def score(list, sign="111", m)
  xyz = Array.new(3, 0)
  list = list.sort_by do |e|
    sum = 0
    3.times{|i| sum += sign[i] == '1' ? e[i] : -e[i]}
    -sum
  end
  list[0...m].each do |e|
    3.times do |i|
      xyz[i] += e[i]
    end
  end
  xyz.inject(0){|s,e| s+e.abs}
end
ans = []
["111", "011", "101", "110", "001", "100", "010", "000"].each do |sign|
  ans << score(xyz, sign, m)
end
puts ans.max
