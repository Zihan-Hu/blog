#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    char a, b;
    cin >> a >> b;
    // 第一个字母 -> 25
    // 第二个字母 -> 1
    // 如果第第二个字母小于第一个字母，那么少掉的那个在它后面，不被算入
    cout << (a - 'a') * 25 + (b - 'a') + (b < a) << '\n';
  }
  return 0;
}
