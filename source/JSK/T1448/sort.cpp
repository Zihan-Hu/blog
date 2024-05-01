#include <algorithm>
#include <iostream>

using namespace std;

const int N = 105;
int a[N];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1, [](int a, int b) { return abs(a) > abs(b); });
  for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
  return 0;
}
