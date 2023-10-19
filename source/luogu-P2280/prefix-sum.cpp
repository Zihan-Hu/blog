#include <iostream>
using namespace std;

const int M = 5005;
int h, w; // 地图长宽
unsigned sum[M][M]; // 空间不够，这是目标兼前缀和

/** 计算区域和。 */
int getAreaSum(int x1, int y1, int x2, int y2) {
  // 使 (x1, y1) 是左上角，(x2, y2) 是右下角
  if (x1 > x2) swap(x1, x2);
  if (y1 > y2) swap(y1, y2);
  return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}

int main() {
  int n, r;
  cin >> n >> r;
  for (int i = 1; i <= n; ++i) {
    int x, y, v;
    cin >> x >> y >> v;
    x += 1; y += 1; // 坐标从 0 开始，所以整体 + 1
    sum[x][y] = v;
    w = max(w, x);
    h = max(h, y);
  }
  w = h = 5003;
  // 计算前缀和
  for (int i = 1; i <= w; ++i) for (int j = 1; j <= h; ++j) {
    sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + sum[i][j];
  }
  int ans = 0;
  for (int i = 1; i + r - 1 <= w; ++i) for (int j = 1; j + r - 1 <= h; ++j) {
    ans = max(ans, getAreaSum(i, j, i + r - 1, j + r - 1));
  }
  cout << ans << '\n';
  return 0;
}
