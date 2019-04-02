n,k=gets.not_nil!.split.map(&.to_i)
puts gets.not_nil!.split.map(&.to_i).sort_by{|len| -len}[0...k].sum
