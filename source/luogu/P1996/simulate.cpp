#include <iostream>
#include <list>
using namespace std;

list<int> game;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) game.push_back(i);
  auto cur = game.begin();
  int i = 0;
  while (game.size()) {
    ++i;
    if (i == m) {
      auto d = cur;
      ++cur;
      cout << *d << ' ';
      game.erase(d);
      i = 0;
    } else {
      ++cur;
    }
    if (cur == game.end()) cur = game.begin();
  }
  return 0;
}
