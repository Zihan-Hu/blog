#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (a < b) swap(a, b);
    if (b < c) swap(b, c);
    if (a < b) swap(a, b);
    int l = a - b - c - 1, r = a + b + c - 3;
    cout << (m >= l && m <= r ? "YES" : "NO") << '\n';
  }
  return 0;
}
