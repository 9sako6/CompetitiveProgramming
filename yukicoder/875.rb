class SegmentTree
  def initialize(n, unity, &func)
    @size_r = 1
    while @size_r < n
      @size_r <<= 2
    end
    @func = func
    @unity = unity
    @dat = Array.new(@size_r * 2, @unity)
  end

  # set, a is 0-indexed
  def set(a, v)
    @dat[a + @size_r] = v
  end

  def build
    (@size_r - 1).downto(1) do |k|
      @dat[k] = @func.call(@dat[k * 2], @dat[k * 2 + 1])
    end
  end
  def update(i, x)
    i += @size_r
    @dat[i] = x
    i >>= 1
    while i > 0
      @dat[i] = @func.call(@dat[i * 2], @dat[i * 2 + 1])
      i >>= 1
    end
    true
  end

  # get [a, b), a and b are 0-indexed
  def get(a, b)
    vleft = vright = @unity
    left = a + @size_r
    right = b + @size_r
    while (left < right)
      if (left & 1) == 1
        vleft = @func.call(vleft, @dat[left])
        left += 1
      end
      if (right & 1) == 1
        right -= 1
        vright = @func.call(@dat[right], vright)
      end
      left >>= 1
      right >>= 1
    end
    return @func.call(vleft, vright)
  end

  def [](k)
    @dat[@size_r + k]
  end
end

N, q = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
h = {}
seg = SegmentTree.new(N, 1 << 31) { |x, y| x > y ? y : x }

N.times do |i|
  h[a[i]] = i
  seg.set(i, a[i])
end
seg.build
ans = []
q.times do
  c, l, r = gets.split.map(&:to_i)
  l -= 1
  r -= 1
  if c == 1
    tmpl = seg.get(l, l + 1)
    tmpr = seg.get(r, r + 1)
    seg.update(l, tmpr)
    seg.update(r, tmpl)
    h[tmpr] = l
    h[tmpl] = r
  else
    ans << h[seg.get(l, r + 1)] + 1
  end
end

puts ans
