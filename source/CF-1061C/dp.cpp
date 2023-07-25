#include <cstdio>
using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;
int a[N], f[N][N];

int main() {
  int n, ans = 0;
  scanf("%d", &n);
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), f[i][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      f[i][j] = f[i - 1][j]; // 不加入
      if (a[i] % j == 0) f[i][j] += f[i - 1][j - 1]; // 加入
    }
  }
  for (int i = 1; i <= n; ++i) ans += f[n][i]; // 统计总方案数
  printf("%d", ans);
  return 0;
}

