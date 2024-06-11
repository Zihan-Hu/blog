#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;  // k^2 < n 时无解
  if (1ll * k * k < n) {
    cout << -1;
    return 0;
  }
  int top = n;
  // 每次放 k 长度的单增序列，直到不够 k 个
  while (top >= k) {
    for (int i = k; i >= 1; --i) {
      cout << top - i + 1 << ' ';
    }
    top -= k;
  }
  // 剩下的也按单增放掉
  for (int i = 1; i <= top; ++i) cout << i << ' ';
  return 0;
}
