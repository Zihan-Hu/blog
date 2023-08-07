#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1e6 + 5;
int n;
LL diff[N];

inline int lowbit(int x) {
  return x & -x;
}

/** 给从 `l` 到 `r` 的区间中每个元素加上 `v`。 */
inline void add(int l, int r, int v) {
  for (int i = l; i <= n; i += lowbit(i)) diff[i] += v;
  for (int i = r + 1; i <= n; i += lowbit(i)) diff[i] -= v;
}

/** 查询 1 ~ `x` 的前缀和。 */
LL sum(int x) {
  LL ans = 0;
  for (int i = x; i > 0; i -= lowbit(i)) ans += diff[i];
  return ans;
}

/** 查询 `x` 的值。 */
inline LL query(int x) {
  return sum(x);
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  int u;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &u);
    add(i, i, u);
  }
  while (q--) {
    int op, x, y, z;
    scanf("%d", &op);
    switch (op) {
      case 1:
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        break;
      case 2:
        scanf("%d", &x);
        printf("%lld\n", query(x));
        break;
    }
  }
  return 0;
}
