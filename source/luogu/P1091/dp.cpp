#include <climits>
#include <iostream>
using namespace std;

const int N = 105, T = 240;
int f1[N], f2[N], t[N], n;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> t[i];
  // 从左往右查找 LIS
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      if (t[j] < t[i]) f1[i] = max(f1[i], f1[j]);
    }
    ++f1[i];  // 要加上 `t[i]` 自己
  }
  // 从右往左查找 LIS
  for (int i = n; i >= 1; --i) {
    for (int j = n; j > i; --j) {
      if (t[j] < t[i]) f2[i] = max(f2[i], f2[j]);
    }
    ++f2[i];
  }
  int ans = INT_MAX;
  // 计算答案时要加上中间的
  for (int i = 1; i <= n; ++i) ans = min(ans, n - f1[i] - f2[i] + 1);
  cout << ans;
  return 0;
}
