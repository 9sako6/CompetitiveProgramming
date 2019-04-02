

def make?(a, k, val) # k(1-indexed)番目まででvalを作れるか
  return $memo[k][val] if $memo[k][val] != -1
  return val == 0 if k == 0
  # k-1番目まででval || val - a[k-1]を作れるか
  if val - a[k - 1] < 0
    return $memo[k][val] = make?(a, k - 1, val)
  else
    return $memo[k][val] = make?(a, k - 1, val - a[k - 1]) || make?(a, k - 1, val)
  end
end

n = gets.to_i
a = gets.split.map(&:to_i)
$memo = Array.new(n + 1) { Array.new(10010, -1) }

ans = 0
sum = a.inject(&:+)
0.upto(sum) do |val|
  ans += 1 if make?(a, n, val)
end
p ans
