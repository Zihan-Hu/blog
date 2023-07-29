#include <iostream>
using namespace std;

const int N = 1e6 + 5;
int st[30][N], f[N], n, m;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> st[0][i];
  for (int i = 2; i <= n; ++i) f[i] = f[i >> 1] + 1;
  for (int k = 1; 1 << k <= n; ++k) {
    for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
      st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
    }
  }
  int k = f[m];
  for (int i = 1; i <= n - m + 1; ++i) {
    cout << min(st[k][i], st[k][i + m - (1 << k)]) << endl;
  }
  return 0;
}
