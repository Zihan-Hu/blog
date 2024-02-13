#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const char ch[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/** `n` 进制转 `m` 进制。 */
string transform(string s, int n, int m) {
  int x = stoi(s, 0, n);  // n 进制转 10 进制（偷懒
  bool un = x < 0;  // 是否负数
  x = abs(x);  // 转成正数计算
  string ans = "";
  while (x != 0) {  // 10 进制转 m 进制
    ans += ch[x % m];
    x /= m;
  }
  if (un) ans += "-";
  reverse(ans.begin(), ans.end());  // 反转
  return ans;
}

int main() {
  string s;
  int n, m;
  cin >> n >> s >> m;
  cout << transform(s, n, m);
  return 0;
}
