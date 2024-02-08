#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  Edge(int v, int w) : v(v), w(w) {}
  int v, w;
};
struct Node {
  int dis, u;
  inline bool operator>(const Node& a) const {
    return this->dis > a.dis;
  }
};

const int INF = 0x3f3f3f3f, BINF = 0x3f;
const int N = 1e5 + 10;
vector<Edge> g[N];
priority_queue<Node, vector<Node>, greater<Node>> q;
int dis[N];
bool vis[N];

void dijkstra(int n, int s) {
  memset(dis, BINF, sizeof(dis));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto e : g[u]) {
      int v = e.v, w = e.w;
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n, m, s, u, v, w;
  cin >> n >> m >> s;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  dijkstra(n, s);
  for (int i = 1; i <= n; ++i) {
    cout << (dis[i] == INF ? INT_MAX : dis[i]) << ' ';
  }
  return 0;
}
