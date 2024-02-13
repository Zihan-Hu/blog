#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

const double S3 = sqrt(3.0);

inline LL count(double l, double r) {
  return max(0ll, LL(floor(r) - ceil(l) + 1));
}

int main() {
  int t;
  scanf("%d", &t);
  LL x1, y1, x2, y2, a, b, ans;
  while (t--) {
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
     // 横排无偏移
    a = count(x1 / S3 + 0.5, x2 / S3 - 0.5);  // 横排
    b = count((y1 + 1) / 3.0, (y2 - 1) / 3.0);  // 竖排
    ans = a * b;
     // 横排有偏移
    a = count(x1 / S3, x2 / S3 - 1);  // 横排
    b = count((y1 + 1) / 3.0 - 0.5, (y2 - 1) / 3.0 - 0.5);  // 竖排
    ans += a * b;
    printf("%lld\n", ans);
  }
  return 0;
}
