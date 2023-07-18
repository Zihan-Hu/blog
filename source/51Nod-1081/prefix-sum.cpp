#include <iostream>
using std::cin; using std::cout; using std::endl;

const int N = 5e4 + 5;
int a[N], n;
long long plus[N]; // 前缀和，不开 long long 会 WA

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    plus[i] = plus[i - 1] + a[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int i, l;
    cin >> i >> l;
    cout << plus[i + l - 1] - plus[i - 1] << endl;
  }
  return 0;
}
