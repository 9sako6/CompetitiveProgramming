N=gets.to_i
xy=[]
N.times do
  xy << gets.split.map(&:to_i)
end
if N==1
  p 1
  exit(0)
end
cands = Hash.new(0)
xy.sort_by!{|pos| pos[1]}
xy.sort_by!{|pos| pos[0]}
(N-1).times do |i|
  ((i+1)...N).each do |j|
    cands[[xy[i][0]-xy[j][0], xy[i][1]-xy[j][1]].inspect] += 1
  end
end
num = cands.values.sort_by!{|v| -v}[0]
p 1+(num-1)+(N-num*2)