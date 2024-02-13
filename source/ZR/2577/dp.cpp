#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;

const int N = 4e4 + 5;
LL a[N], b[N];
LL f1[N], f2[N];
LL (*current)[N] = &f1, (*last)[N] = &f2;

int main() {
  register int n, m = 1;
  scanf("%llu", &n);
  for (register int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (register int i = 1; i <= n; ++i) scanf("%d", &b[i]);
  register LL ans = 0;
  for (register int i = 1; i <= n; ++i) {
    swap(current, last);  // 避免使用 memcpy
    (*current)[0] = (*last)[0] + a[i];
    for (register int j = 1; j <= i; ++j) {
      if (i == j) {
        (*current)[j] = (*last)[j - 1] + b[i] - j;
      } else {
        (*current)[j] = max((*last)[j - 1] + b[i] - j, (*last)[j] + a[i]);
      }
    }
  }
  for (register int i = 0; i <= n; ++i) ans = max(ans, (*current)[i]);
  printf("%llu", ans);
  return 0;
}
