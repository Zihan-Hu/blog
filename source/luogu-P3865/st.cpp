#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int st[20][N], f[N], a[N], n, m;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);  // @attention cin 会 TLE
    st[0][i] = a[i];  // 初始化 st 表底层
  }
  for (int i = 2; i <= n; ++i) f[i] = f[i >> 1] + 1;  // 计算 log
  for (int k = 1; 1 << k <= n; ++k) {  // 动态规划构造 st 表
     // 把 $2^k$ 长度的区间分解成两个长度为 $2^{k - 1}$ 的区间
     // 求最大/最小时可以重复，所以重叠起来的两个区间的最大值，即为区间最大值
    for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
      st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    int k = f[r - l + 1];
    printf("%d\n", max(st[k][l], st[k][r - (1 << k) + 1]));
  }
  return 0;
}
