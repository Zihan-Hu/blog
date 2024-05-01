#include <iostream>
using namespace std;

enum Action {
  CUTTER,  // 剪刀
  STONE,   // 石头
  PAPER,   // 布
  XYR,     // 蜥蜴人
  SPK,     // 斯波克
};
const bool results[5][5] = {
    // 题目图中阴影部分与右上角对称，但需要取相反值
    {0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1},
    {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0},
};
const int GROUP = 205;
int group1[GROUP], group2[GROUP];  // 周期

int main() {
  int n, n1, n2, r1 = 0, r2 = 0;
  cin >> n >> n1 >> n2;
  int a, b;
  for (int i = 0; i < n1; ++i) cin >> group1[i];
  for (int i = 0; i < n2; ++i) cin >> group2[i];
  for (int i = 0; i < n; ++i) {
    a = group1[i % n1];
    b = group2[i % n2];
    r1 += results[a][b];
    r2 += results[b][a];
  }
  cout << r1 << ' ' << r2;
  return 0;
}
