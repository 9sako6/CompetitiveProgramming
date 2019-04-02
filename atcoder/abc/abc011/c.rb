n = gets.to_i
ng = 3.times.map { gets.to_i }.sort
if ng.include?(n)
  puts "NO"
  exit
end
num = n
100.times do
  if !ng.include?(num - 3) && num - 3 >= 0
    num -= 3
  elsif !ng.include?(num - 2) && num - 2 >= 0
    num -= 2
  elsif !ng.include?(num - 1) && num - 1 >= 0
    num -= 1
  elsif ng.include?(num - 1)
    puts "NO"
    exit
  end
  if num == 0
    puts "YES"
    exit
  end
end
puts (num == 0 ? "YES" : "NO")
