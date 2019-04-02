N,K=gets.split.map(&:to_i)
if K==1 || N==1
  puts 0
else
  puts N-K
end