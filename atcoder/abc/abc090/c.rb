N,M=gets.split.map(&:to_i)
if N>=2 && M>=2
  puts (N-2)*(M-2)
else
  if N==1 && M==1
    puts 1
  elsif N >= 2
    puts N-2
  else
    puts M-2
  end
end