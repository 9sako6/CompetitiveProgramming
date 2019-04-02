#
# merge sort
#   [left, right)
#

$comperation_count = 0

def merge_sort(arr)
  return arr if arr.size <= 1
  mid = arr.size / 2
  left = merge_sort(arr[0...mid])
  right = merge_sort(arr[mid...arr.size])
  ret = []
  while !left.empty? || !right.empty?
    $comperation_count += 1
    if left.empty?
      ret << right.shift
    else
      if right.empty?
        ret << left.shift
      else
        puts "? #{left[0]} #{right[0]}"
        STDOUT.flush
        ans = gets.chomp
        if ans == "<"
          ret << left.shift
        else
          ret << right.shift
        end
      end
    end
  end
  ret
end

n, q = gets.split.map(&:to_i)
ans = merge_sort([*0...n].map { |i| (i + 65).chr }) * ""
puts "! #{ans}"
