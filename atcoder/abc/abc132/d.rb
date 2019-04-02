MOD=10**9+7
N,K=gets.split.map(&:to_i)
(1..K).each do |i|
  # 端っこの赤玉の分け方
  # 赤玉がa個あるなら
  a = K
  c_edge = 
