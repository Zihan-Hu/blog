#include <iostream>
#include <queue>
using namespace std;

const int N = 205;
int n, k[N];
bool vis[N];
queue<int> q;

int bfs(int start, int target) {
  if (start == target) return 0;
  q.push(start);
  int ans = 0;
  while (!q.empty()) {
    int len = q.size();
    ++ans;
    for (int i = 1; i <= len; ++i) {
      int h = q.front();
      q.pop();
      vis[h] = 1; // 标记已达
      int up = h + k[h], down = h - k[h];
      if (up <= n) { // 可上
        if (up == target) return ans;
        if (!vis[up]) q.push(up); // 如果再去到达过的楼层就会循环
      }
      if (down >= 1) { // 可下
        if (down == target) return ans;
        if (!vis[down]) q.push(down); // 所以剪枝
      }
    }
  }
  return -1;
}

int main() {
  int a, b;
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) cin >> k[i];
  cout << bfs(a, b);
  return 0;
}
