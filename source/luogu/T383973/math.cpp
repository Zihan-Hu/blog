#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> Point;

vector<Point> el;

/** 计算 (x, y) 被扩散到的时间。 */
int calc(int x, int y) {
  int ret = INT_MAX;
  for (Point &p : el) {
    ret = min(ret, abs(x - p.first) + abs(y - p.second));  // 曼哈顿距离
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m, t;
  cin >> n >> m >> t;
  int x, y;
  for (int i = 1; i <= m; ++i) {
    cin >> x >> y;
    el.emplace_back(x, y);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << (calc(i, j) <= t) << ' ';
    }
    cout << '\n';
  }
  return 0;
}
