#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 2e5 + 5;
int a[N], b[N], t[N], c[N], n, m, k, s;
LL f[N]; // 不开 long long 见祖宗！

bool check(int mid) {
  LL t1 = INT64_MAX, t2 = INT64_MAX; // 最小汇率
  for (int i = 1; i <= mid; ++i) {
    t1 = min(t1, LL(a[i]));
    t2 = min(t2, LL(b[i]));
  }
  for (int i = 1; i <= m; ++i) { // 处理每个商品
    switch (t[i]) { // 都按最小汇率兑换
      case 1: f[i] = t1 * c[i]; break;
      case 2: f[i] = t2 * c[i]; break;
    }
  }
  sort(f + 1, f + m + 1);
  LL ans = 0;
  for (int i = 1; i <= k; ++i) ans += f[i]; // 买了最便宜的 `k` 个
  return (ans <= s); // 是否能买够
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  for (int i = 1; i <= m; ++i) scanf("%d%d", &t[i], &c[i]);
  int l = 1, r = n, mid;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid)) r = mid - 1;
    else l = mid + 1;
  }
  printf("%d", (l <= n) ? l : -1); // 越界则为无解
  return 0;
}
