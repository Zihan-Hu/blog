#include <iostream>
using namespace std;

const int N = 1e5 + 5;
int a[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int sum = 0, minn = 1;
  for (int i = 1; i <= n; ++i) {
    sum += (a[i] % 2 == 0) ? (a[i] - 1) : a[i];
    if (a[i] < a[minn]) minn = i;
  }
  if (sum % 2 == 0) sum -= (a[minn] % 2 == 0) ? (a[minn] - 1) : a[minn];
  printf("%d", sum);
  return 0;
}
