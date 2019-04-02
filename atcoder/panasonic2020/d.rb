n = gets.to_i
q = [["a", "a"]]
ans = []
until q.empty?
  s, c_max = q.shift
  if s.size < n
    "a".upto(c_max) do |c|
      q << [s + c, c_max]
    end
    q << [s + ((c_max).ord + 1).chr, ((c_max).ord + 1).chr]
  else
    ans << s
  end
end
puts ans
