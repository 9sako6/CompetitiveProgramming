x = gets.to_i
1.upto(1000) do |i|
  if i**4 == x
    puts i
    exit
  end
end