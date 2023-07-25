#include <iostream>
using namespace std;

/**
 * 移动。
 * @param block 积木编号，从小到大
 * @param source 积木所在的柱子
 * @param middle 过渡的柱子
 * @param target 要移动到的柱子
 */
void move(int block, char source, char middle, char target) {
  if (block == 1) { // 最小，直接移
    cout << "1:" << source << "->" << target << endl;
    return;
  }
  move(block - 1, source, target, middle);
  cout << block << ':' << source << "->" << target << endl;
  move(block - 1, middle, source, target);
}

int main() {
  int n;
  char a, b, c;
  cin >> n >> a >> b >> c;
  move(n, a, b, c);
  return 0;
}
