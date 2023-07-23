#include <iostream>
#include <cstdio>
using namespace std;

const int N = 60;
int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", &a[i], &b[i]);
    int winner = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] <= 10 && b[i] >= b[winner]) winner = i;
    }
    printf("%d\n", winner);
  }
  return 0;
}
