def dfs(v)
  $d[v] = $cnt
  $cnt += 1
  $g[v].each do |u|
    if !$d[u]
      dfs(u)
    end
  end
  $f[v] = $cnt
  $cnt += 1
end

n = gets.to_i
$g = Array.new(n) { [] }
n.times.map { |i| $g[i] = gets.split.map.map { |x| x.to_i - 1 }[2..-1] }

$d = []
$f = []
$cnt = 1
dfs(0)
p $d, $f
n.times.map { |i| puts "#{i + 1} #{$d[i]} #{$f[i]}" }
