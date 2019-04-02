# 超参考：https://atcoder.jp/contests/arc096/submissions/7526451
N, C = gets.split.map(&:to_i)
sushi = N.times.map { gets.split.map(&:to_i) }

def solve(sushi)
  sumv = 0
  prev = 0
  # 進んで、方向転換して始点に戻るまでに得るカロリ
  gain = [0] + sushi.reverse_each.map { |x, v|
    sumv += v
    prev = [sumv - 2 * (C - x), prev].max
  }
  sumv = 0
  ans = (0...N).map { |i|
    x, v = sushi[i]
    sumv += v
    sumv - x + gain[-i - 2]
  }.max
  ans
end

p [0, solve(sushi), solve(sushi.reverse.map { |x, v| [C - x, v] })].max
