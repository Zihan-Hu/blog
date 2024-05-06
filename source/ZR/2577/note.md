# 问题定义

大问题：前 n 个路口的最大积分。

小问题：前 i 个路口扳动 j 次的最大积分。

# 状态定义

f[i][j] := 前 i 个路口扳动 j 次的最大积分

# 状态转移

对于第 i 个路口 (i >= 1, j <= i)：

- 如果扳动：f[i][j] = f[i - 1][j - 1] + b[i] - j
- 如果不动：f[i][j] = f[i - 1][j] + a[i]

两个中取最大。

# 答案

max(f[n][0], f[n][1], ..., f[n][n])

# 边界

f[i][0] = f[i - 1][0] + b[i]
f[0][j] = 0
f[0][0] = 0

# 压缩