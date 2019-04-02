n = gets.to_i
a = gets.split.map(&:to_i)
if a[0] != 0
  puts 0
  exit
end

mod = 1000000007
cnt = Array.new(n + 1, 0)
cnt[0] = 1
ans = 3

1.upto(n - 1) do |i|
  if a[i] != 0 && cnt[a[i] - 1] <= cnt[a[i]]
    ans *= 0
  end
  if cnt[a[i]] == 0 # 1回めの出現
    ans *= cnt[a[i] - 1]
    ans %= mod
    cnt[a[i]] += 1
  elsif cnt[a[i]] == 1
    if a[i] == 0
      ans *= 2
    else
      ans *= (cnt[a[i] - 1] - cnt[a[i]])
    end
    ans %= mod
    cnt[a[i]] += 1
  elsif cnt[a[i]] == 2
    cnt[a[i]] += 1
  else
    ans *= 0
  end
end
p ans
