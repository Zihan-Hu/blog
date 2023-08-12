#include <iostream>
using namespace std;

/**
 * 快读。
 * @see http://zhengruioi.com/problem/2605
 */
namespace IO {
  const int N = 1e7 + 5;
  char _READ_[N], _PRINT_[N];
  int _READ_POS_, _PRINT_POS_, _READ_LEN_;
  inline char readc() {
#ifndef ONLINE_JUDGE
    return getchar();
#endif
    if (!_READ_POS_) {
      if (feof(stdin)) return -1;
      _READ_LEN_ = fread(_READ_, 1, N, stdin);
    }
    char c = _READ_[_READ_POS_++];
    if (_READ_POS_ == _READ_LEN_) _READ_POS_ = 0;
    return c;
  }
  template<typename T> inline int read(T &x) {
    x = 0; int flag = 1, c;
    while (((c = readc()) < '0' || c > '9') && c != '-')
      if (c < 0) return -1;
    if (c == '-') flag = -1; else x = c - '0';
    while ((c = readc()) >= '0' && c <= '9') x = x * 10 - '0' + c;
    x *= flag; return 0;
  }
}

const int N = 1e7 + 5;
int count[N], n;

int main() {
  IO::read(n);
  int ans = 0; // 异或和
  int last = 0; // 上一个答案
  for (int i = 1; i <= n; ++i) {
    int a;
    IO::read(a);
    ++count[a];
    if (count[a] > count[last]) last = a; // 当前数字的出现次数更多
    else if (count[a] == count[last] && a < last) last = a; // 一样多，但更小
    ans ^= last;
  }
  printf("%d", ans);
  return 0;
}
