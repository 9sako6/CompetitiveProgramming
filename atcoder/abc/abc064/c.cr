n = gets.not_nil!.to_i
d = Array.new(n) { gets.not_nil!.to_i } # 縦並びのn個の整数
# a = gets.not_nil!.split.map(&.to_i).map{|rate| rate < 3200 ? rate : -1}
p d
# max = (cnt["god"] > 0 ? (cnt.keys.size) -1 + cnt["god"] : (cnt.keys.size))
# min = (is_all_god ? 1 : cnt["god"] > 0 ? (cnt.keys.size) - 1 : (cnt.keys.size))
# puts "#{min} #{max}"