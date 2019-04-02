N = gets.to_i
A = gets.split.map(&:to_i)
ans = -1e9

N.times do |i|
  max_t = max_a = -1e9
  N.times do |j|
    next if i == j
    s, t = [i, j].minmax
    taka, aoki = A[s..t].partition.with_index { |a, i| (i + 1).odd? }
    score = [taka.inject(&:+), aoki.inject(&:+)]
    if max_a < score[1]
      max_t, max_a = score
    end
  end
  ans = max_t if max_t > ans
end

p ans
