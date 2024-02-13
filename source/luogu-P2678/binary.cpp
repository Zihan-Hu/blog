#include <iostream>
using namespace std;

const int N = 5e4 + 5, L = 1e9 + 5;
int m, n, d[N];

/**
 * @param dis 最大间距
 * @return 需要移走的岩石数量
 */
int remove(int dis) {
  int ans = 0, last = 0;
  for (int i = 1; i <= n + 1; ++i) {  // 需要遍历到终点
    if (d[i] - last < dis)  // 需要移走
      ++ans;
    else
      last = d[i];
  }
  return ans;
}

int search(int l, int r) {
  int mid;
  while (l + 1 < r) {
    mid = l + r >> 1;
    if (remove(mid) <= m)
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  int l;
  cin >> l >> n >> m;
  if (n == 0) {  // 对于中间无岩石的特判
    cout << l;  // 不特判会输出 `l - 1`
    return 0;
  }
  for (int i = 1; i <= n; ++i) cin >> d[i];
  d[n + 1] = l;  // 终点
  cout << search(1, l);
  return 0;
}
