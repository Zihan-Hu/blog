#include <iostream>
using namespace std;

const int N = 2e5 + 10;
char s[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t, n, m, ansX, ansY, maxCount, maxLeft, maxRight;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    maxCount = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> s;
      bool found = 0;
      int left = -1, cnt = 0;
      for (int j = 0; j < m; ++j) {
        if (s[j] == '#') {
          if (!found) {
            found = 1;
            left = j;
          }
          ++cnt;
        } else if (found) {
          break;
        }
      }
      if (cnt > maxCount) {
        maxCount = cnt;
        ansX = i;
        ansY = left + (cnt + 1 >> 1);
      }
    }
    cout << ansX << ' ' << ansY << '\n';
  }
  return 0;
}
