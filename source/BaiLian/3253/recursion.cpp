#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ULL;
const int N = 20;
ULL r[N][N];  // 缓存

ULL resolve(int n, int m) {
  if (r[n][m]) return r[n][m];  // 有缓存，使用缓存
  if (n < m || (m == 0 && n != 0)) return 0;
  if (n == 0 || n == 1 || m == 1 || n == m) return 1;
  r[n][m] = resolve(n - 1, m - 1) + m * resolve(n - 1, m);  // 保存到缓存
  return r[n][m];
}

int main() {
  int n;
  ULL ans;
  while (cin >> n) {
    ans = 0;
    if (n == 0) {
      cout << '1\n';
      continue;
    }
     // n 个元素划分为成 resolve(n,m) 个集合
    for (int i = 1; i <= n; ++i) ans += resolve(n, i);
    cout << ans << '\n';
  }
  return 0;
}
