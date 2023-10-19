#include <iostream>
using namespace std;
typedef long long LL;

LL a[5], ans = 0;

inline void sort() {
  if (a[1] > a[2]) swap(a[1], a[2]);
  if (a[2] > a[3]) swap(a[2], a[3]);
  if (a[1] > a[2]) swap(a[1], a[2]);
}
inline void minify() {
  LL k = min(min(a[1], a[2]), a[3]);
  a[1] -= k; a[2] -= k; a[3] -= k;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  cin >> a[1] >> a[2] >> a[3];
  minify();
  sort();
  int k;
  while (k) {
    k = a[3] - a[2];
    a[1] += k; a[2] += k;
    ans += k;
    minify();
    sort();
  }
  ans += a[2] + a[3];
  cout << ans;
  return 0;
}
