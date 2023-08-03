#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e3;
int f[N][N], n, m, ans;

int main() {
  memset(f, 0x3f, sizeof(f));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    f[u][v] = f[v][u] = w;
    f[u][u] = f[v][v] = 0;
  }
  for (int k = 1; k <= n; ++k) for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) {
    f[i][j] = min(f[i][k] + f[k][j], f[i][j]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) printf("%d ", f[i][j]);
    printf("\n");
  }
  return 0;
}
