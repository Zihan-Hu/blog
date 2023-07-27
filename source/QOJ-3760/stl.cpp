/** @warning 本程序 TLE */

#include <iostream>
#include <list>
using namespace std;

const int N = 1e5 + 5;
list<int> l[N];

void exec(int a, int b) {
  l[a].splice(l[a].end(), l[b]); // 连接
  l[a].reverse(); // 反转
  l[b].clear(); // 清空
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    for (int i = 1; i <= n; ++i) {
      l[i].clear();
      l[i].push_back(i);
    }
    while (m--) {
      int a, b;
      cin >> a >> b;
      exec(a, b);
    }
    cout << l[1].size() << ' ';
    for (auto v : l[1]) cout << v << ' ';
    cout << endl;
  }
  return 0;
}
