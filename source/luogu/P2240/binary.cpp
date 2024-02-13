#include <iostream>
using namespace std;

const int N = 1e5 + 5, L = 1e8 + 5;
int a[N], n, k;

bool check(int l) {
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans += a[i] / l;
  return ans >= k;
}

int search(int l, int r) {
  int mid;
  while (l + 1 < r) {
    mid = l + r >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << search(0, L);  // 从 0 开始，无解时无需特判
  return 0;
}
