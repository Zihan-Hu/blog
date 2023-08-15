#include <iostream>
using namespace std;
typedef long long LL; // 不开 long long 见祖宗

const int N = 1e5 + 5;
int n, a[N];
LL preSum[N]; // 前缀和
LL sufAbsSum[N]; // 后缀绝对值和

int main() {
  scanf("%d", &n);
  scanf("%d", &a[1]);
  preSum[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    LL x; char c;
    scanf(" %c %d", &c, &x);
    a[i] = (c == '-') ? -x : x; // 把符号合并到数值中
    preSum[i] = preSum[i - 1] + LL(a[i]); // 计算 preSum
  }
  for (int i = n; i >= 1; --i) { // 计算 sufAbsSum
    sufAbsSum[i] = sufAbsSum[i + 1] + llabs(a[i]);
  }
  LL ans = preSum[n]; // 初始为不加括号
  for (int i = 1; i < n; ++i) { // 枚举第一个括号的位置，在第 i 个数前
    if (a[i] > 0) continue; // 如果括号前面是加号，那就白加了
    // 如果是减号，把它当作第一个减号，那么第二个减号之后，每项都有方案变为正
    int next; // 第二个减号的位置
    for (next = i + 1; next <= n; ++next) {
      if (a[next] < 0) break;
    }
    if (next > n) break; // 找不到第二个减号
    // (i 及其前面的和) - (两个减号之间的和) + (第二个减号及其后的绝对值的和)
    ans = max(ans, preSum[i] - (preSum[next - 1] - preSum[i]) + sufAbsSum[next]);
  }
  printf("%lld", ans);
  return 0;
}
