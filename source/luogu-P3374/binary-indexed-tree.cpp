#include <iostream>
using namespace std;
typedef long long LL;

const int N = 5e5 + 5;
int a[N], n;
LL sum[N];

/** 从下标为 `n` 的节点开始向上更新。 */
inline void pushup(int n) {
  sum[n] = sum[n << 1] + sum[(n << 1) + 1];
}

/**
 * 查询区间和。
 * @param a 区间左边界
 * @param b 区间右边界
 * @param l 当前节点左边界
 * @param r 当前节点右边界
 * @param k 节点下标
 */
int query(int a, int b, int l = 1, int r = n, int k = 1) {
  if (a > r || b < l) return 0;
  if (a <= l && b >= r) return sum[k];
  int mid = l + r >> 1;
  return (
    query(a, b, l, mid, k << 1)
    + query(a, b, mid + 1, r, (k << 1) + 1)
  );
}

/** 构建线段树。 */
void build(int l = 1, int r = n, int k = 1) {
  if (l == r) {
    sum[k] = a[l];
  } else {
    int mid = l + r >> 1;
    build(l, mid, k << 1);
    build(mid + 1, r, (k << 1) + 1);
    pushup(k);
  }
}

/**
 * 更新树上数据。
 * @param k 更新的节点下标
 * @param v 更新的值
 * @param l 当前节点表示的区间的左边界
 * @param r 当前节点表示的区间的右边界
 * @param idx 当前遍历到的节点下标
 */
void update(int k, int v, int l = 1, int r = n, int idx = 1) {
  if (l == r) {
    sum[idx] = v;
  } else {
    int mid = l + r >> 1;
    if (k <= mid) update(k, v, l, mid, idx << 1); // 需要更新的在左边
    else update(k, v, mid + 1, r, (idx << 1) + 1); // 需要更新的在右边
    sum[idx] = sum[idx << 1] + sum[(idx << 1) + 1];
  }
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  build();
  while (m--) {
    int opt, x, y;
    scanf("%d%d%d", &opt, &x, &y);
    switch (opt) {
      case 1:
        update(x, a[x] + y);
        a[x] += y;
        break;
      case 2:
        cout << query(x, y) << '\n';
        break;
    }
  }
  return 0;
}
