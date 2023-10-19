#include <iostream>
#include <cstring>
using namespace std;

const int N = 305;
int f[N][N], sum[N], n;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  memset(f, 0x3f, sizeof(f));
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int m;
    cin >> m;
    sum[i] = sum[i - 1] + m;
    f[i][i] = 0;
  }
  for (int len = 2; len <= n; ++len) for (int l = 1; l + len - 1 <= n; ++l) {
    int r = l + len - 1;
    for (int k = l; k < r; ++k) {
      f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
    }
  }
  cout << f[1][n];
  return 0;
}
