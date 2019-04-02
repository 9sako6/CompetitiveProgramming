$cntl = Hash.new(0)
$cntr = Hash.new(0)
$cntp = Hash.new(0)
$cnt = 0

def rec(a, i, history)
  if a.size == 1
    p history
    history.each do |hi|
      tmp = hi.split("-")
      $cntl[tmp[0]] += 1
      $cntr[tmp[1]] += 1
      $cntp[hi] += 1
    end
    $cnt += 1
    return history
  end
  (0...(a.size - 1)).each do |k|
    # puts "#{" " * i} #{k}"
    b = a.dup
    b.delete_at(k)
    # $cntl[a[k+1]] += 1
    # $cntr[a[k]] += 1
    rec(b, i + 1, history + ["#{a[k + 1]}-#{a[k]}"])
  end
end

n = gets.to_i
a = [*1..n]

rec(a, 1, [])
pp $cntl
pp $cntr
pp $cntp
pp $cnt
