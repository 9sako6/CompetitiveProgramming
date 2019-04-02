# frozen_string_literal: true

def solver1(n, m, l, r, s)
  ans = 0
  m.times do |i|
    cnt = 0
    n.times do |j|
      next if l[j] <= i + 1 && i + 1 <= r[j]

      cnt += s[j]
    end
    ans = [ans, cnt].max
  end
  p ans
end

def solver2(n, m, l, r, s)
  full_score = s.inject(&:+)
  t = Array.new(m + 3, 0)
  n.times do |i|
    t[l[i]] += s[i]
    t[r[i] + 1] -= s[i]
  end
  tmp = 0
  p t.map { |ti| tmp += ti }.map { |si| full_score - si }[1..m].max
end

n, m = gets.split.map(&:to_i)
l, r, s = n.times.map { gets.split.map(&:to_i) }.transpose

if n <= 8 && m <= 8
  solver1(n, m, l, r, s)
else
  solver2(n, m, l, r, s)
end
