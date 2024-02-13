#include <iostream>
#include <climits>
#include <string>
using namespace std;

const int N = 2e5 + 5;

/** 判断 `c` 四舍五入后数值是否变大。 */
inline bool needRound(char c) {
  return c >= '5';
}
/**
 * 查找最左的可以四舍五入的下标。
 * @param s 数值
 * @param last 上一次四舍五入的下标
 */
int findRound(const string& s, int last) {
  int ans = INT_MAX;
  for (int i = 0; i < last; ++i) {
    if (needRound(s[i])) {
      ans = i;
      break;
    }
  }
  if (ans != INT_MAX && s[ans - 1] == '4') {  // 可以继续进位
    for (int i = ans; i >= 0; ++i) {
      if (s[ans - 1] == '4')
        --ans;
      else
        break;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int t;
  cin >> t;
  string s;
  s.reserve(N);  // 预分配内存
  while (t--) {
    cin >> s;
    int w = findRound(s, s.size());
    while (w != INT_MAX && w != 0) {  // 直到不能操作或在最高位操作
      ++s[w - 1];
      for (int i = w; i < s.size(); ++i) s[i] = '0';
      w = findRound(s, w);
    }
    if (w == 0) {  // 在最高位操作
      cout << 1;  // 进位
      for (int i = 1; i <= s.size(); ++i) cout << 0;
    } else {
      cout << s;
    }
    cout << '\n';
  }
  return 0;
}
