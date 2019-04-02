n, k = gets.split.map(&:to_i)
rsp = gets.split.map(&:to_i) + [0]
j = gets.chomp
te = ""
j.each_char.with_index do |c, i|
  win = (c == "r" ? "p" : (c == "s" ? "r" : "s"))
  if i >= k
    if te[i - k] == win
      # win = (win == "r" ? "s" : (c == "s" ? "p" : "r")) # ?
      win = "x"
    end
  end
  te << win
end
# p te
p te.tr("rspx", "0123").chars.map(&:to_i).map { |x| rsp[x] }.inject(&:+)
