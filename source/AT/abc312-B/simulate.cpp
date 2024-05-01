#include <iostream>
using namespace std;

const int N = 105;
char code[N][N];
int n, m;

bool check(int x, int y) {
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {  // 左上角
      if (code[x + i][y + j] != '#') return 0;
    }
  for (int i = 6; i < 9; ++i)
    for (int j = 6; j < 9; ++j) {  // 右上角
      if (code[x + i][y + j] != '#') return 0;
    }
  for (int i = 0; i < 4; ++i) {  // 左上角周围
    if (code[x + i][y + 3] != '.' || code[x + 3][y + i] != '.') return 0;
  }
  for (int i = 0; i < 4; ++i) {  // 右上角周围
    if (code[x + 5 + i][y + 5] != '.' || code[x + 5][y + 5 + i] != '.') {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> code[i][j];
  for (int i = 1; i <= n - 8; ++i)
    for (int j = 1; j <= m - 8; ++j) {
      if (check(i, j)) cout << i << ' ' << j << '\n';
    }
  return 0;
}
