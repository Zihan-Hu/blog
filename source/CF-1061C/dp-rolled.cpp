#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int a[N], f[N], f2[N]; // 对应滚动优化前：`f[i] = f, f2 = f[i - 1]`

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  f2[0] = 1; // 对应 `f[0][0] = 1`
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    f[0] = 1; // 对应 `f[i][0] = 1`
    for (int j = 1; j <= n; ++j) {
      f[j] = f2[j]; // 不加入
      if (a[i] % j == 0) f[j] += f2[j - 1]; // 加入
    }
    memcpy(f2, f, sizeof(f)); // 滚动
  }
  for (int i = 1; i <= n; ++i) ans += f[i]; // 统计总方案数
  printf("%d", ans);
  return 0;
}