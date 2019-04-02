A = gets.split.map(&:to_i)
ans = []
stack = []
stack << []
while !stack.empty?
  list = stack.pop
  if list.size == A.size
    ans << list
  else
    A.each do |ai|
      stack << list + [ai] if !list.include?(ai)
    end
  end
end

p ans
