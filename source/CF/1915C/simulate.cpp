#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;

/** 判断是否完全平方数。 */
inline bool isSquare(LL x) {
  LL n = sqrt(x);
  return n * n == x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int n, a;
  LL sum;
  while (t--) {
    cin >> n;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a;
      sum += a;
    }
    cout << (isSquare(sum) ? "YES" : "NO") << '\n';
  }
  return 0;
}
