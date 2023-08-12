#include <iostream>
#include <queue>
using namespace std;

const int N = 1e6 + 5;
int a[N], maxs[N];
deque<char> ans;

int main() {
  int n;
  scanf("%d", &n);
  // @attention 输入输出全部从 0 到 n
  for (int i = 0; i <= n; ++i) scanf("%d", &a[i]);
  ans.push_back(a[0]);
  for (int i = 1; i <= n; ++i) {
    // 答案的第一位一定是当前最大的，
    // 所以`a[i]` 只要不小于当前答案第一位，就是 `a[0...i]` 中最大的
    if (a[i] >= ans.front()) ans.push_front(a[i]);
    else ans.push_back(a[i]);
  }
  for (int i = 0; i <= n; ++i) {
    printf("%d", ans.front());
    ans.pop_front();
  }
  return 0;
}
