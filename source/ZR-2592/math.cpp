#include <iostream>
using namespace std;
typedef long long LL;

const int dx[] = {1, 1, 2, 2, -1, -1, -2, -2},
          dy[] = {2, -2, 1, -1, 2, -2, 1, -1};

inline bool valid(LL x, LL y) {
  return (x >= 1 && y >= 1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    LL x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    bool ok = 0;
    for (int i = 0; i < 8; ++i) {
      LL x = x1 + dx[i], y = y1 + dy[i];
      if (valid(x, y) && x + y != x2 + y2 && abs(x2 - x) != abs(y2 - y)) {
        ok = 1;
        break;
      }
    }
    cout << ok << '\n';
  }
  return 0;
}
