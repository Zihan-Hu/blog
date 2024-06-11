#include <iostream>
using namespace std;

// 注意 N 需要开到两倍，防止加上选择通道的奖励后溢出
const int N = 2e4 + 10, INF = 0x3f3f3f3f;
int a[N], b[N], f[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < (n << 1); ++i) f[i] = -INF;
  f[0] = 0;
  for (int i = 0; i < (n << 1); ++i) {
    for (int j = 0; j < m; ++j) {
      if (i - a[j] < 0) continue;
      f[i] = max(f[i], f[i - a[j]] + b[i - a[j]]);
    }
  }
  int ans = -INF;
  for (int i = n; i < (n << 1); ++i) ans = max(ans, f[i]);
  cout << ans;
  return 0;
}
