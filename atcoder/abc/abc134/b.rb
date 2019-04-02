n,d=gets.split.map(&:to_i)
p n/(2*d+1)+(n % (2*d+1)==0 ? 0 : 1)