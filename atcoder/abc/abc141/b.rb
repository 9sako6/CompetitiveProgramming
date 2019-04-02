s=gets.chomp
odd =[]
even = []
s.each_char.with_index do |c, i|
    if i.even?
        if ["R", "U", "D"].include?(c)
            next
        else
            puts "No"
            exit
        end
    else
        if ["L", "U", "D"].include?(c)
            next
        else
            puts "No"
            exit
        end
    end
end
puts "Yes"