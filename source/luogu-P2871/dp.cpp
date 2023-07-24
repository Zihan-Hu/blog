#include <iostream>
using namespace std;

const int N = 1e5;
int f[N], w[N], d[N], n, m;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> w[i] >> d[i];
  for (int i = 1; i <= n; ++i) for (int j = m; j >= 1; --j) {
    if (w[i] <= j) f[j] = max(f[j], f[j - w[i]] + d[i]);
  }
  cout << f[m];
  return 0;
}
