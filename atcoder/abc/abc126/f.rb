M,K=gets.split.map(&:to_i)
if K >= 2**M || M==1 && K==1
  puts -1
else
  if K==0
    arr = []
    (0...2**M).each do |i|
      arr << i
      arr << i
    end
    puts arr * ' '
  else
    arr = (0...K).to_a + (K+1...2**M).to_a
    arr << K
    arr += arr[0...-1].reverse
    arr << K
    puts arr * ' '
  end
end