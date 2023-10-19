#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int Num; // @attention 注意数据范围是 unsigned int

const int N = 3e6 + 10;
vector<Num> a[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  int s;
  Num u;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 1; j <= s; ++j) {
      cin >> u;
      a[i].push_back(u);
    }
  }
  Num x, y, ans = 0;
  while (q--) {
    cin >> x >> y;
    ans ^= a[x][y - 1];
  }
  cout << ans;
  return 0;
}
