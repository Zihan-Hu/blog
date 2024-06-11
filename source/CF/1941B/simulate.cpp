#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int a[N], n;

bool solve() {
  for (int i = 1; i <= n - 2; ++i) {
    if (a[i] < 0) return 0;
    if (a[i] % 2 == 1) {
      --a[i];
      a[i + 1] -= 2;
      --a[i + 2];
    }
    a[i + 1] -= a[i] << 1;
    a[i + 2] -= a[i];
  }
  return a[n - 1] == 0 && a[n] == 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
