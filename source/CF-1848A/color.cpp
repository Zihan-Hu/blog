#include <iostream>
using namespace std;

/** 颜色。 */
enum Color {
  WHITE,
  BLACK,
};
/** 位置转颜色。 */
inline Color toColor(int x, int y) {
  return (x % 2 ^ y % 2) ? Color::BLACK : Color::WHITE;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k, x, y;
    bool lose = false; // 是否必败
    cin >> n >> m >> k >> x >> y;
    auto c = toColor(x, y);
    int ux, uy;
    for (int i = 1; i <= k; ++i) {
      cin >> ux >> uy;
      if (lose) continue; // 读完本组数据，不影响其他组
      if (toColor(ux, uy) == c) lose = true; // 同色必败
    }
    cout << (lose ? "NO" : "YES") << '\n';
  }
  return 0;
}
