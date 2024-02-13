#include <iostream>
using namespace std;

const int N = 2e6;
bool a[N];
int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = n; i >= 1; i -= 2) {
    cout << !a[i] << ' ';
  }
  for (int i = (n % 2 == 0) ? 1 : 2; i <= n; i += 2) {
    cout << a[i] << ' ';
  }
  return 0;
}
