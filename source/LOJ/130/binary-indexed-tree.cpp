#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1e6 + 5;
int n;
LL a[N];

inline int lowbit(int x) {
  return x & -x;
}

/** 给第 `k` 个元素加上 `v`。 */
void add(int k, int v) {
  for (int i = k; i <= n; i += lowbit(i)) a[i] += v;
}

/** 查询 1 ~ `x` 的前缀和。 */
LL sum(int x) {
  LL ans = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ans += a[i];
  return ans;
}

/** 查询 `l` 到 `r` 的区间和。 */
inline LL query(int l, int r) {
  return sum(r) - sum(l - 1);
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  int u;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &u);
    add(i, u);
  }
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    switch (op) {
      case 1: add(x, y); break;
      case 2: printf("%lld\n", query(x, y)); break;
    }
  }
  return 0;
}
