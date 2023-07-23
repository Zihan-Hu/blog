#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 4e4 + 5;
LL a[N], b[N];
LL d[N]; // 每个路口扳动后积分的变化量（不耐烦的扣分除外）

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    d[i] = b[i] - a[i]; // 顺便计算 `d`
  }
  sort(d + 1, d + n + 1, [](int a, int b) { return a > b; });
  LL ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] > i) ans += d[i] - i; // 这里减掉不耐烦的扣分
    ans += a[i]; // 不扳动的都要加
  }
  printf("%lld", ans);
  return 0;
}
