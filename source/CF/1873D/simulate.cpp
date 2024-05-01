#include <iostream>
#include <string>
using namespace std;

const int N = 2e5 + 10;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  int n, k, ans;
  string s;
  s.reserve(N);
  while (t--) {
    cin >> n >> k >> s;
    ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'B') {
        i += k - 1;
        ++ans;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
