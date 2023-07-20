#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 5e4 + 5;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) printf("%d\n", a[i]);
  return 0;
}
