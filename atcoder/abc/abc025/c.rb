def score(a)
  taka, nao = 0, 0
  2.times do |i|
    3.times do |j|
      if a[i * 3 + j] == a[(i + 1) * 3 + j]
        taka += B[i][j]
      else
        nao += B[i][j]
      end
    end
  end
  3.times do |i|
    2.times do |j|
      if a[i * 3 + j] == a[i * 3 + j + 1]
        taka += C[i][j]
      else
        nao += C[i][j]
      end
    end
  end
  # [taka, nao]
  taka
end

$memo = {}

def search(board, n)
  # ミニマックス法
  return score(board) if n == 9
  return $memo[board] if $memo[board]
  if n.even? # ちょくだい
    max = -1
    3.times do |i|
      3.times do |j|
        next if board[i * 3 + j] != "?"
        board[i * 3 + j] = "o"
        max = [max, search(board, n + 1)].max
        board[i * 3 + j] = "?"
      end
    end
    $memo[board] = max
    return max
  else
    min = Float::INFINITY
    3.times do |i|
      3.times do |j|
        next if board[i * 3 + j] != "?"
        board[i * 3 + j] = "x"
        min = [min, search(board, n + 1)].min
        board[i * 3 + j] = "?"
      end
    end
    $memo[board] = min
    return min
  end
end

B = 2.times.map { gets.split.map(&:to_i) }
C = 3.times.map { gets.split.map(&:to_i) }

sum = score("x" * 9)

t = search("?" * 9, 0)
p t
p sum - t
