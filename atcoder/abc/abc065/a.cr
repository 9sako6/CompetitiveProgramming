x,a,b=gets.not_nil!.split.map(&.to_i)
if b-a > x
    puts "dangerous"
else
    puts b-a <= 0 ? "delicious" : "safe"
end