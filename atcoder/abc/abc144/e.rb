n, $k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i).sort
f = gets.split.map(&:to_i).sort.reverse
$cost = []
n.times do |i|
  $cost << [a[i], f[i], a[i] * f[i]]
end
$cost.sort_by! { |c| -c[2] }

def check(x) # x以下のコストにできるか
  cnt = 0
  $cost.each do |c|
    if c[2] > x
      cnt += (c[0] - x / c[1])
    else
      break
    end
  end
  cnt <= $k
end

ok = 10**18
ng = -1
while (ok - ng).abs > 1
  mid = (ok + ng) / 2
  if check(mid)
    ok = mid
  else
    ng = mid
  end
end
p ok
