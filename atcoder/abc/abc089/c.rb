N=gets.to_i
names = Hash.new{|h,k|h[k]=[]}

N.times do
  name = gets.chomp
  names[name[0].downcase] << name
end
ans = 0
choices = ['mar', 'mac', 'mah', 'mrc', 'mrh', 'mch', 'arc', 'arh', 'ach', 'rch']
choices.each do |seq|
  t = 1
  seq.chars do |c|
    t *= names[c].size
  end
  ans += t
end
puts ans