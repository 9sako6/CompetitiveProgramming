H, W = gets.split.map(&:to_i)
# 横3
max_h = H / 3 + (H % 3 == 0 ? 0 : 1)
min_h = H / 3
ans = max_h * W - min_h * W
# 縦3
max_w = W / 3 + (W % 3 == 0 ? 0 : 1)
min_w = W / 3
ans = [ans, max_w * H - min_w * H].min

max_h = H / 2 + (H % 2 == 0 ? 0 : 1)
min_h = H / 2
max_w = W / 2 + (W % 2 == 0 ? 0 : 1)
min_w = W / 2
# 縦2, 横1
# 1. 横1の高さが最大
ans = [ans, max_h * W - min_h * min_w].min
# # 2. 横1の高さが最小
ans = [ans, min_h * W - max_h * min_w].min
# # 縦1, 横2
# # 1. 縦1の幅が最大
ans = [ans, max_w * H - min_w * min_h].min
# # 2. 横1の高さが最小
ans = [ans, min_w * H - max_w * min_h].min
p ans
