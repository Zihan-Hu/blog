#include <cstdio>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;

const int MOD = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  ULL f1;  // 当前计算的 f
  ULL f2 = 1;  // 上一个 f，此处是边界
  ULL fp = 1;  // 用到的 3 的幂
  for (int i = 1; i <= n; ++i) {
    f1 = (fp - f2 + MOD) % MOD;  // fp 取模过，大小关系不确定
    f2 = f1;
    fp = 3 * fp % MOD;  // 不模会爆 unsigned long long，此处可证无副作用
  }
  printf("%llu", f1);
  return 0;
}
