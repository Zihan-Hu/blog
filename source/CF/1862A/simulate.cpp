#include <iostream>
using namespace std;

const int N = 30;
const char like[] = "vika";
char s[N][N];

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    int cur = 0;
    bool yes = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (s[j][i] == like[cur]) {
          ++cur;
          break;
        }
      }
      if (cur == 4) {
        yes = 1;
        break;
      }
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
  return 0;
}
