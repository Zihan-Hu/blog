#include <iostream>
using namespace std;

const int N = 205;
int f[N][N], e[N], n;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> e[i];
    e[i + n] = e[i]; // 倍长
  }
  int ans = 0;
  for (int i = 2; i < (n << 1); ++i) { // 枚举右界
    for (int j = i - 1; (i - j < n) && (j >= 1); --j) { // 枚举左界
      for (int k = j; k < i; ++k) { // 枚举合并的中点
        f[j][i] = max(
          f[j][i], // 原
          f[j][k] + f[k + 1][i] + e[j] * e[k + 1] * e[i + 1] // 左 + 右 + 新
        );
      }
      ans = max(ans, f[j][i]);
    }
  }
  cout << ans;
  return 0;
}
