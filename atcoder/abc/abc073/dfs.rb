N,K = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

ans = []
stack = []
stack << [0, 0]
while !stack.empty?
  id, sum = stack.pop
  if id == N
    ans << sum
  else
    stack << [id+1, sum]
    stack << [id+1, sum+a[id]]
  end
end

p ans

__END__
4 13
1 2 4 7