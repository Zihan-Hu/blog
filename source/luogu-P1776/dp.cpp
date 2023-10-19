#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int f[N], v[N], w[N], n, m, idx;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    // 二进制拆分
    for (int j = 1; j <= z; j <<= 1) { // @note `z -= j` 不能放在 `for` 的最后面
      v[++idx] = x * j;
      w[idx] = y * j;
      z -= j;
    }
    if (z) {
      v[++idx] = x * z;
      w[idx] = y * z;
    }
  }
  for (int i = 1; i <= idx; ++i) for (int j = m; j >= w[i]; --j) {
    f[j] = max(f[j], f[j - w[i]] + v[i]);
  }
  cout << f[m];
  return 0;
}
