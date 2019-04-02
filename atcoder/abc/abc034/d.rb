n, k = gets.split.map(&:to_i)
wp = []
n.times do
  wp << gets.split.map(&:to_i)
end
wp.sort_by! { |x| -x[1] }
all = 0.0
salt = 0.0
k.times do |i|
  wi, pi = wp[i]
  all += 100 * wi / pi.to_f
  salt += wi.to_f
end

p salt / all

