n, x, m = gets.split.map(&:to_i)

memo = {}

prev = x
memo[x] = 0
a = [x]
offset = 0
start_pos = 0
end_pos = 0
1.upto(m - 1) do |i|
  prev = prev * prev % m
  a << prev
  if memo[prev]
    start_pos = memo[prev]
    offset = start_pos - 1
    end_pos = i - 1
    break
  else
    memo[prev] = i
  end
end

cycle_sum = a[start_pos..end_pos].inject(&:+)
cycle_len = end_pos - start_pos + 1

ans = 0

if offset >= 0
  ans += a[0..offset].inject(&:+)
  n -= offset + 1
end

ans += cycle_sum * (n / cycle_len)
ans += a[start_pos, (n % cycle_len)].inject(&:+).to_i
puts ans
