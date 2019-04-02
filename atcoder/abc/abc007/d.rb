A, B = gets.split.map(&:to_i)
# source: https://torus711.hatenablog.com/entry/20150423/1429794075
# dp[ 決めた桁数 ][ 未満フラグ ][ 4 または 9 を含むか ] := 総数
# dp[i][j][k] -> dp[i+1][j || (d < D)][k || d==4 || d==9] (Dはstrの当該桁)
def solve(str)
  dp = Array.new(32 + 1) { Array.new(2) { Array.new(2, 0) } }
  dp[0][0][0] = 1 # ?
  str.each_char.with_index do |c, i|
    2.times do |j|
      2.times do |k|
        (0..(j == 1 ? 9 : c.to_i)).each do |d|
          k_flag = (k == 1 ? 1 : (d == 4 || d == 9 ? 1 : 0))
          if j == 1
            dp[i + 1][j][k_flag] += dp[i][j][k]
          else
            dp[i + 1][d < c.to_i ? 1 : 0][k_flag] += dp[i][j][k]
          end
        end
      end
    end
  end
  dp[str.size][0][1] + dp[str.size][1][1]
end

p solve(B.to_s) - solve((A - 1).to_s)
