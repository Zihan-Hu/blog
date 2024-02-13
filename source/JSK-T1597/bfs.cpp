#include <iostream>
#include <climits>
#include <queue>
using namespace std;

struct Point {
  Point(): Point(0, 0) {}
  Point(int x, int y): x(x), y(y) {}
  bool operator==(const Point& p) const {
    return this->x == p.x && this->y == p.y;
  }
  int x, y;
};


const int N = 20;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool blocked[N][N], vis[N][N];
int n, m, ans = INT_MAX;
queue<Point> q;

inline bool valid(Point p) {
  if (p.x < 1 || p.x > m || p.y < 1 || p.y > n) return 0;
  if (blocked[p.x][p.y] || vis[p.x][p.y]) return 0;
  return 1;
}
inline bool win(Point p) {
  return p.x == 1 || p.x == n || p.y == 1 || p.y == m;
}

/**
 * @param p 搜索起点
 * @param step 当前已走步数
 */
void dfs(Point p, int step) {
  if (step > ans) return;  // 已不能更优，剪枝
  if (win(p)) {  // 因为已进行最优性剪枝，确保了答案更优
    ans = step;
    return;
  }
  for (int i = 0; i < 4; ++i) {
    Point u(p.x + dx[i], p.y + dy[i]);
    if (valid(u)) {
      vis[u.x][u.y] = 1;
      dfs(u, step + 1);
      vis[u.x][u.y] = 0;
    }
  }
}

int main() {
  Point start;
  cin >> n >> m;
  char c;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> c;
      switch (c) {
        case '#': blocked[i][j] = 1; break;
        case '@': start = Point(i, j); break;
      }
    }
  }
  dfs(start, 0);
  cout << ((ans == INT_MAX) ? -1 : ans);  // 这里必须加括号，否则会 WA
  return 0;
}
