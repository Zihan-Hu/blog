#include <iostream>
using namespace std;
typedef long long LL;

const int N = 1 << 18;
int a[N], sum[N], tagMul[N], tagAdd[N], n, m;

/**
 * 下放树上标记。
 * @param k 标记所在的节点下标
 * @param l 更新的区间的左边界
 * @param r 更新的区间的右边界
 */
void pushdown(int k, int l, int r) {
  int ls = k << 1, rs = (k << 1) + 1; // 左右边界
  if (tagMul[k] != 1) { // 下放乘法标记
    tagMul[ls] = LL(tagMul[ls]) * tagMul[k] % m;
    tagAdd[ls] = LL(tagAdd[ls]) * tagMul[k] % m;
    tagMul[rs] = LL(tagMul[rs]) * tagMul[k] % m;
    tagAdd[rs] = LL(tagAdd[rs]) * tagMul[k] % m;
    sum[ls] = LL(sum[ls]) * tagMul[k] % m;
    sum[rs] = LL(sum[rs]) * tagMul[k] % m;
    tagMul[k] = 1;
  }
  if (tagAdd[k] != 0) { // 下放加法标记
    int mid = l + r >> 1;
    tagAdd[ls] = (tagAdd[ls] + tagAdd[k]) % m;
    tagAdd[rs] = (tagAdd[rs] + tagAdd[k]) % m;
    sum[ls] = (sum[ls] + LL(tagAdd[k]) * (mid - l + 1)) % m;
    sum[rs] = (sum[rs] + LL(tagAdd[k]) * (r - mid)) % m;
    tagAdd[k] = 0;
  }
}

/** 从下标为 `k` 的节点开始向上更新。 */
inline void pushup(int k) {
  sum[k] = (sum[k << 1] + sum[(k << 1) + 1]) % m;
}

/** 构建线段树。 */
void build(int l = 1, int r = n, int k = 1) {
  tagMul[k] = 1;
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
 * @param a 更新的左边界
 * @param b 更新的右边界
 * @param mul 需要更新的乘法标记
 * @param add 需要更新的加法标记
 * @param l 当前节点表示的区间的左边界
 * @param r 当前节点表示的区间的右边界
 * @param k 当前节点的下标
 */
void update(int a, int b, int mul, int add, int l = 1, int r = n, int k = 1) {
  if (a > r || b < l) return;
  if (a <= l && b >= r) {
    tagMul[k] = LL(tagMul[k]) * mul % m;
    tagAdd[k] = (LL(tagAdd[k]) * mul + add) % m;
    sum[k] = (LL(sum[k]) * mul + LL(add) * (r - l + 1)) % m;
  } else {
    pushdown(k, l, r);
    int mid = l + r >> 1;
    update(a, b, mul, add, l, mid, k << 1);
    update(a, b, mul, add, mid + 1, r, (k << 1) + 1);
    pushup(k);
  }
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
  pushdown(k, l, r); // 先下放标记
  int mid = l + r >> 1;
  return (
    query(a, b, l, mid, k << 1)
    + query(a, b, mid + 1, r, (k << 1) + 1)
  ) % m;
}

int main() {
  int t;
  cin >> n >> t >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build();
  while (t--) {
    int opt, x, y, k;
    cin >> opt >> x >> y;
    switch (opt) {
      case 1:
        cin >> k;
        update(x, y, k, 0);
        break;
      case 2:
        cin >> k;
        update(x, y, 1, k);
        break;
      case 3:
        cout << query(x, y) << '\n';
        break;
    }
  }
  return 0;
}
