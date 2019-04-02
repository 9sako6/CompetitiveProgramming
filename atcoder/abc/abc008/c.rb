# frozen_string_literal: true

n = gets.to_i
c = n.times.map { gets.to_i }

def divnum(a, c)
  cnt = 0
  c.each do |ci|
    cnt += 1 if a % ci == 0
  end
  cnt
end

ans = 0
c.each do |ci|
  s = divnum(ci, c)
  ans += (s - 1).odd? ? 0.5 : (s + 1).to_f / (2 * s)
end
p ans
