N=gets.to_i
as=gets.split.map(&:to_i)
num_odd=0
num_4=0
num_2=0
as.each do |a|
  if a.odd?
    num_odd += 1
  else
    a % 4 == 0 ? num_4 += 1 : num_2 += 1
  end
end

if num_4 >= num_odd
  puts 'Yes'
elsif num_4 == num_odd-1
  puts num_2 == 0 ? 'Yes' : 'No'
else
  puts 'No'
end