#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  cin >> s;
  // 对字典序来说，越前面的越重要，所以替换最前面一个 fs 为 sf 即可
  int pos = s.find("fs");
  if (pos != -1) s.replace(pos, 2, "sf");
  cout << s;
  return 0;
}
