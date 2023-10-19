#include <iostream>
using namespace std;
int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, u, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> u;
      sum += u;
    }
    cout << ((sum % 2 == 0) ? "YES" : "NO") << '\n';
  }
  return 0;
}
