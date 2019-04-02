# frozen_string_literal: true

$h, $w = gets.split.map(&:to_i)
$a = $h.times.map { gets.split.map(&:to_i) }.flatten
MOD = 1_000_000_007

$dp = Array.new($h * $w,-1)

def rec(y, x)
  return $dp[y * $w + x] if $dp[y * $w + x] != -1

  ret = 1
  ayx = $a[y * $w + x]
  if x - 1 >= 0 && $a[y * $w + x - 1] < ayx
    ret += rec(y, x - 1)
    ret %= MOD if ret >= MOD
  end
  if x + 1 < $w && $a[y * $w + x + 1] < ayx
    ret += rec(y, x + 1)
    ret %= MOD if ret >= MOD
  end
  if y - 1 >= 0 && $a[(y - 1) * $w + x] < ayx
    ret += rec(y - 1, x)
    ret %= MOD if ret >= MOD
  end
  if y + 1 < $h && $a[(y + 1) * $w + x] < ayx
    ret += rec(y + 1, x)
    ret %= MOD if ret >= MOD
  end

  $dp[y * $w + x] = ret
end

ans = 0

$h.times do |i|
  $w.times do |j|
    ans += rec(i, j)
    ans %= MOD if ans >= MOD
  end
end
p ans
