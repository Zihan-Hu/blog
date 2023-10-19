#include <iostream>
using namespace std;
typedef long long LL;

const int N = 2e5 + 10;
int a[N];
LL sum[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n;
  LL k;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  LL l = 0, r = 2e14, mid, ans = 0, t, num;
  while (l <= r) {
    mid = (l + r) >> 1;
    t = 1;
    num = 0;
    for (int i = 2; i <= n; ++i) {
      while (i - t > 1) {
        if (min(sum[i] - sum[t + 1], sum[i - 1] - sum[t]) >= mid) ++t;
        else break;
      }
      if (min(sum[i] - sum[t], sum[i - 1] - sum[t - 1]) >= mid) num += t;
    }
    if (num >= k) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}
