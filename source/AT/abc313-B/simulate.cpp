#include <iostream>
using namespace std;

const int N = 55;
int n, m;
bool thin[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    thin[b] = 1;
  }
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    if (!thin[i]) {
      if (ans == -1) {
        ans = i;
      } else {
        cout << -1;
        return 0;
      }
    }
  }
  cout << ans;
  return 0;
}
