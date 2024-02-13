#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N] = {-1}, n;

int search(int x) {
  if (a[1] > x) return 0;
  int l = 1, r = n + 1, mid;
  while (l + 1 < r) {
    mid = (l + r >> 1);
    if (a[mid] > x)
      r = mid;
    else
      l = mid;
  }
  return l;
}

int main() {
  int m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  while (m--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", a[search(x)]);
  }
  return 0;
}
