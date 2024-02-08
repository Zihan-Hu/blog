#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

struct Edge {
  Edge(int v, int w) : v(v), w(w) {}
  int v, w;
};

const int INF = 0x3f3f3f3f, BINF = 0x3f;
const int N = 1e5 + 10;
vector<Edge> g[N];
int dis[N];
bool vis[N];

void dijkstra(int n, int s) {
  memset(dis, BINF, sizeof(dis));
  dis[s] = 0;
  for (int i = 1; i <= n; ++i) {
    int u = 0, mind = INF;
    for (int j = 1; j <= n; ++j) {
      if (!vis[j] && dis[j] < mind) {
        u = j;
        mind = dis[j];
      }
    }
    vis[u] = 1;
    for (auto e : g[u]) {
      int v = e.v, w = e.w;
      if (dis[v] > dis[u] + w) dis[v] = dis[u] + w;
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
