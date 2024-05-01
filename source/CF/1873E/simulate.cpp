#include <algorithm>
#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int a[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int n, x, ans, sum;
  while (t--) {
    cin >> n >> x;
    ans = sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int i;
    for (i = 1; i <= n; ++i) {
      if (i != 1 && a[i - 1] == a[i]) continue;
      sum += (a[i] - a[i - 1]) * (i - 1);
      if (sum > x) {
        sum -= (a[i] - a[i - 1]) * (i - 1);
        break;
      }
      ans = a[i];
    }
    ans += (0, (x - sum)) / (i - 1);
    cout << ans << '\n';
  }
  return 0;
}
