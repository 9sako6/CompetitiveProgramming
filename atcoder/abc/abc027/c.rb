N = gets.to_i
flag_t = true
x = 1
leng = N.to_s(2).size

def check(num, flag)
  if num > N
    puts (flag ? "Aoki" : "Takahashi")
    exit
  end
end

while true
  if flag_t
    if leng.odd?
      x = 2 * x + 1
      check(x, flag_t)
    else
      x = 2 * x
      check(x, flag_t)
    end
    flag_t = false
  else
    if leng.odd?
      x = 2 * x
      check(x, flag_t)
    else
      x = 2 * x + 1
      check(x, flag_t)
    end
    flag_t = true
  end
end
