A,B,C,X,Y=gets.split.map(&:to_i)

if A+B > C*2
  common = [X,Y].min
  ans = C*2*common
  if X > Y
    rest = X-Y
    ans += (A < 2*C ? rest*A : rest*2*C)
  elsif Y > X
    rest = Y-X
    ans += (B < 2*C ? rest*B : rest*2*C)
  end
  puts ans
else
  puts A*X+B*Y
end
