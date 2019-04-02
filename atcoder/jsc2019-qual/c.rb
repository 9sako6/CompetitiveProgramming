n = gets.to_i
s = gets.chomp
MOD = 10**9+7
if s[0] == "W" || s[-1] == "W"
  puts 0
  exit
elsif s =~ /BWBW/
  puts 0
  exit
end
fw = Array.new(2*n, 0)
fw[0] = fw[-1] = 1
prev_char = s[0]
(1...n).each do |i|
  if prev_char == "B"
    if s[i] == "B"
      fw[i] = fw[i-1]
    elsif s[i] == "W"
      fw[i] = fw[i-1] +1
      prev_char = "W"
    end
  elsif prev_char == "W"
    if s[i] == "W"
      fw[i] = fw[i-1]
    elsif s[i] == "B"
      fw[i] = fw[i-1] +1
      prev_char = "B"
    end
  end
end
prev_char = "B"
(2*n-2).downto(n) do |i|
  if prev_char == "B"
    if s[i] == "B"
      fw[i] = fw[i+1]
    elsif s[i] == "W"
      fw[i] = fw[i+1] +1
      prev_char = "W"
    end
  elsif prev_char == "W"
    if s[i] == "W"
      fw[i] = fw[i+1]
    elsif s[i] == "B"
      fw[i] = fw[i+1] +1
      prev_char = "B"
    end
  end
end
# p s.chars
# p fw.map(&:to_s)
p fw.inject(1){|seki, x| seki * x % MOD}


