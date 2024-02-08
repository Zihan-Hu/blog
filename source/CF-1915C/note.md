起初认为 `sqrt` 是浮点运算，成本很高，所以直接写了预处理+二分：

```cpp
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;

const ULL M = 2e14, R = 14142136;
ULL sq[R + 10]; // M 内的完全平方数

/** 预处理完全平方数。 */
void preprocess() {
  ULL cur = 0;
  int index = 1;
  for (ULL i = 1; cur <= M; ++i) {
    cur = i * i;
    sq[index++] = cur;
  }
}
bool query(int x) {
  int l = 1, r = R;
  ULL mid, cur;
  while (l <= r) {
    mid = l + (r - l >> 1);
    cur = sq[mid];
    if (cur > x) r = mid - 1;
    else if (cur < x) l = mid + 1;
    else return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  preprocess();
  int t;
  cin >> t;
  int n, a;
  ULL sum;
  while (t--) {
    cin >> n;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a;
      sum += a;
    }
    cout << (query(sum) ? "YES" : "NO") << '\n';
  }
  return 0;
}
```

后来[被提醒](https://codeforces.com/blog/entry/123952?#comment-1099308)才知道 `sqrt` 是 `O(log n)`。。所以就有了 `./simulate.cpp`
