def beki(n)
  cnt = 0
  while n >= 2
    if n % 2 == 0
      n /= 2
      cnt += 1
    else
      break
    end
  end
  cnt
end

n = gets.to_i
a = gets.split.map(&:to_i)
p a.map { |ai| beki(ai) }.min
