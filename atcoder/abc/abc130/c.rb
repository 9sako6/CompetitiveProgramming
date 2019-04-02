W,H,x,y=gets.split.map(&:to_f)
xm=W/2.0
ym=H/2.0
if x==xm && y==ym
  puts "#{sprintf("%.10f", H*W/2)} #{1}"
else
  puts "#{sprintf("%.10f", H*W/2)} #{0}"
end