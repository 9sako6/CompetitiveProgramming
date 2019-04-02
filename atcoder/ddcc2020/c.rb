h, w, k = gets.split.map(&:to_i)
s = h.times.map { gets.chomp }

id = {} # [i,j]をkeyとするイチゴの番号
cnt = 1
non_empty_row = Array.new(h, false)
s.each_with_index do |row, i|
  w.times do |j|
    if s[i][j] == "#"
      non_empty_row[i] = true
      id["#{i}, #{j}"] = cnt
      cnt += 1
    end
  end
end

cake = Array.new(h) { Array.new(w, "?") }

# まずは横方向
h.times do |i|
  row = s[i]
  prev = "?"
  w.times do |j|
    if row[j] == "#"
      cake[i][j] = id["#{i}, #{j}"]
      prev = id["#{i}, #{j}"]
    else
      cake[i][j] = prev
    end
  end
  # 右端が?だったらその行にはイチゴがないのでとりあえずぱす
  next if cake[i][-1] == "?"
  next if cake[i][0] != "?"

  first_ichigo_id = -1
  cake[i].each_with_index do |c, j|
    if c != "?"
      first_ichigo_id = j
      break
    end
  end
  # pp first_ichigo_id
  w.times do |j|
    if cake[i][j] == "?"
      cake[i][j] = cake[i][first_ichigo_id]
    end
  end
end



empty_i = non_empty_row.map.with_index{|_, i| i}.select{|i| non_empty_row[i] == false}
nonempty_i = non_empty_row.map.with_index{|_, i| i}.select{|i| non_empty_row[i] == true}
# p empty_i
# p nonempty_i
# pp cake
# 上にある?行に対して上のをコピーする
empty_i.each do |i|
  # iより大きいjをnonempty_iからさがす
  nonempty_i.each do |j|
    if j > i
      cake[i] = cake[j]
      break
    end
  end
end

h.times do |i|
  if cake[i].include?("?")
    cake[i] = cake[nonempty_i[-1]]
  end
end


puts cake.map{|tmp| tmp.join(" ")}
