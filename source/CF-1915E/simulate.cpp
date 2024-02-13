// 赛时没写完，结束后写了二十分钟就写完了！！

#include <iostream>
#include <map>
using namespace std;
typedef long long LL;

const int N = 2e5 + 5, M = 1e5 + 5;
LL a[N], sum[N];
multimap<LL, int> diff;

inline LL getDiff(int i) {
  return (i % 2 == 1 ? sum[i] - sum[i - 1] : sum[i - 1] - sum[i]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n;
    diff.clear();
    bool ok = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (ok) continue;
      if (i == 1)
        sum[i] = a[i];
      else
        sum[i] = sum[i - 2] + a[i];
      LL d = getDiff(i);
      if (d == 0) ok = 1;
      diff.emplace(getDiff(i), i);
    }
    if (!ok) {
      for (int i = 1; i <= n; ++i) {
        if (diff.count(getDiff(i)) > 1) {
          ok = 1;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}
