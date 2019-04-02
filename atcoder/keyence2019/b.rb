s = gets.chomp
if s[0..6] == "keyence"
  puts 'YES'
elsif s[-7..-1] == "keyence"
  puts 'YES'
elsif s[0]+s[-6..-1] == "keyence"
  puts 'YES'
elsif s[0..1]+s[-5..-1] == "keyence"
  puts 'YES'
elsif s[0..2]+s[-4..-1] == "keyence"
  puts 'YES'
elsif s[0..3]+s[-3..-1] == "keyence"
  puts 'YES'
elsif s[0..4]+s[-2..-1] == "keyence"
  puts 'YES'
elsif s[0..5]+s[-1] == "keyence"
  puts 'YES'
else
  puts 'NO'
end