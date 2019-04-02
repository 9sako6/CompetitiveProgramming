rgb=gets.not_nil!.split.join.to_i
puts rgb % 4 == 0 ? "YES" : "NO"