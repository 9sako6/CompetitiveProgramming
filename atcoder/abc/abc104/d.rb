s=gets.chomp
N=s.size
a = 0
ab = 0
all = 1
ans = 0
MOD = 10**9+7
N.times do |i|
  if s[i] == 'A'
    a += all
  elsif s[i] == 'B'
    ab += a
  elsif s[i] == 'C'
    ans += ab
  else
    ans = ans*3 + ab
    ab = ab*3 + a
    a = a*3 + all
    all *= 3
  end
  a %= MOD
  ab %= MOD
  ans %= MOD
  all %= MOD
end
p ans# % MOD