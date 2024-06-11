#include <iostream>
#include <vector>
using namespace std;

const int N = 3e5 + 10;
int u[N], v[N];
vector<int> rev[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i];
    rev[u[i]].emplace_back(i);
  }
  for (int i = 1; i <= m; ++i) {
    rev[i].emplace_back(m + 1);
  }
  for (int i = 1; i <= m; ++i) {
    int j = 1, found = 0;
    for (int index : rev[u[i]]) {
      while (j != index) {
        if (u[i] != u[j] && u[i] != v[j]) {
          found = j;
          break;
        }
        ++j;
      }
      if (found != 0) break;
      ++j;
    }
    cout << found << ' ';
  }
  return 0;
}
