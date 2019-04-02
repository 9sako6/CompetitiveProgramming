n = gets.to_i
if n <= 9
  puts n
  exit
elsif 10 <= n && n <= 99
  puts 9
  exit
elsif 100 <= n && n <= 999
  puts 9 + (n-100+1)
  exit
elsif 1000 <= n && n <= 9999
  puts 9 + 900
  exit
elsif 10000 <= n && n <= 99999
  puts 9 + 900 + (n-10000+1)
  exit
else
  puts 90909
  exit
end
