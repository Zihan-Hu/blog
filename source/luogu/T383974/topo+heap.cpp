#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 305;
int a[N][N];
int input[N * N];                                  // 入度
bool contain[N * N];                               // 编号 i 是否存在
vector<int> used[N * N];                           // 依赖 i 的边
priority_queue<int, vector<int>, greater<int>> q;  // 当前可取的积木

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  int t = INT_MIN;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      if (i > 1 && a[i][j] != a[i - 1][j]) {  // 记录依赖关系
        used[a[i - 1][j]].push_back(a[i][j]);
      }
      contain[a[i][j]] = 1;
      t = max(t, a[i][j]);
    }
  for (int i = 1; i <= t; ++i) {
    if (used[i].empty()) continue;
    sort(used[i].begin(), used[i].end());
    // 去重边
    used[i].erase(unique(used[i].begin(), used[i].end()), used[i].end());
    // 计算入度
    for (int u : used[i]) ++input[u];
  }
  for (int i = 1; i <= t; ++i) {
    if (contain[i] && input[i] == 0) q.push(i);  // 初始可以取的入队
  }
  int cur;
  while (!q.empty()) {
    cur = q.top();
    cout << cur << ' ';
    // 删边，重新计算入度
    q.pop();
    for (int u : used[cur]) {
      --input[u];
      if (input[u] == 0) q.push(u);  // 新的可取积木入队
    }
  }
  return 0;
}
