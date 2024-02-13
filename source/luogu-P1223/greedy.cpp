#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e3 + 5;
int a[N];
int t[N];  // `t[i]` 是 `a[i]` 在输入中的序号

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    t[i] = i;
  }
  for (int i = 1; i <= n - 1; ++i) {  // 冒泡排序
    bool swapped = 0;
    for (int j = 1; j <= n - i; ++j) {
      if (a[j] > a[j + 1]) {
        swapped = 1;
        swap(a[j], a[j + 1]);
        swap(t[j], t[j + 1]);
      }
    }
    if (!swapped) break;
  }
  for (int i = 1; i <= n; ++i) printf("%d ", t[i]);
  unsigned long long sum = 0;
  for (int i = 1; i <= n; ++i) sum += (n - i) * a[i];
  printf("\n%.2f", sum * 1.0 / n);
  return 0;
}
