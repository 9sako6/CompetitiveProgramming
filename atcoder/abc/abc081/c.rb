n = gets.to_i
a_list = gets.split.map(&:to_i)
cnt = Hash.new(0)
a_list.each do |a|
  cnt[a] += 1
end
hen_cands = cnt.select{|k,v| v >= 2}.to_a.sort_by{|a| -a[0]}
if hen_cands.empty?
  puts 0
elsif hen_cands[0] && hen_cands.size == 1
  hen_cands[0][1] < 4 ? puts(0) : puts(hen_cands[0][0]**2)
else
  hen_cands[0][1] < 4 ? puts(hen_cands[0][0]*hen_cands[1][0]) : puts(hen_cands[0][0]**2)
end

