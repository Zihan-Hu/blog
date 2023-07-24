#include <iostream>
using namespace std;
typedef long long LL;

const int T = 1e7 + 5, M = 1e4 + 5;
LL a[M], b[M], f[T];

int main() {
  int t, m;
  cin >> t >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    for (int j = a[i]; j <= t; j++) {
      f[j] = max(f[j], f[j - a[i]] + b[i]);
    }
  }
  cout << f[t];
  return 0;
}
