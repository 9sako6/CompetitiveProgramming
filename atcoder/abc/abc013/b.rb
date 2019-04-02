mn, mx = 2.times.map { gets.to_i }.minmax
p [mx - mn, 10 + mn - mx].min
