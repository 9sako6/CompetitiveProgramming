s = gets.chomp
ans = []
i = 0
while i < s.size
  tmp = i
  while s[i] == "R"
    i += 1
  end
  r = i - tmp
  while s[i] == "L"
    i += 1
  end
  l = i - r - tmp
  if (l + r).odd?
    if r > l
      if (r - 1).odd? # 反転
        valR = (l + r) / 2
        valL = (l + r) / 2 + 1
      else
        valR = (l + r) / 2 + 1
        valL = (l + r) / 2
      end
    else
      if (l - 1).odd? # 反転
        valR = (l + r) / 2 + 1
        valL = (l + r) / 2
      else
        valR = (l + r) / 2
        valL = (l + r) / 2 + 1
      end
    end
  else
    valR = valL = (l + r) / 2
  end
  (r - 1).times do
    ans << 0
  end
  ans << valR
  ans << valL
  (l - 1).times do
    ans << 0
  end
end

puts ans * " "
