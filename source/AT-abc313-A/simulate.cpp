#include <iostream>
using namespace std;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, x, maxn = -1;
  cin >> n;
  cin >> x;
  for (int i = 2; i <= n; ++i) {
    int a;
    cin >> a;
    maxn = max(maxn, a);
  }
  cout << max(0, maxn - x + 1);
  return 0;
}
