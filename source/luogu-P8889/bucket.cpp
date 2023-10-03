/**
 * 更多注释见 luogu-B3691
 * @see ../luogu-B3691/bucket.cpp
 */
#include <cstdio>
#include <unordered_map>
using namespace std;
typedef long long LL;

const int N = 5e5 + 10;
const int NULL_FLAG = -1;
LL a[N], b[N];
unordered_map<LL, bool> cnt, seg;

int cut(LL arr[], int end) {
  int ret = 0;
  arr[0] = NULL_FLAG;
  for (int i = 1; i <= end; ++i) {
    if (seg[arr[i]]) {
      arr[i] = NULL_FLAG;
      if (arr[i - 1] != NULL_FLAG) ++ret;
    }
  }
  ret += arr[end] != NULL_FLAG;
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
    cnt[a[i]] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%lld", &b[i]);
    seg[b[i]] = cnt[b[i]];
  }
  printf("%d", cut(a, n));
  return 0;
}
