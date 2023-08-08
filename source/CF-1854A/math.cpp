#include <iostream>
using namespace std;
int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, u, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> u;
      sum += u;
    }
    cout << ((sum % 2 == 0) ? "YES" : "NO") << endl;
  }
  return 0;
}
