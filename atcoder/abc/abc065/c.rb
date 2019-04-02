MOD = 10**9+7
N, M = gets.split.map(&:to_i)
if (N-M).abs > 1
  puts 0
  exit(0)
end

def fact(n)
  (1..n).inject(1){|r,i|r*i%MOD}
end

if N==M
  f = fact(N)
  puts f*f*2%MOD
else
  N, M = M, N if N < M
  f = fact(M)
  puts f*f*N%MOD
end
