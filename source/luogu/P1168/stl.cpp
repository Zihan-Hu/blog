#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(0); cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int u;
    cin >> u;
    v.insert(upper_bound(v.begin(), v.end(), u), u);
    if (i % 2 == 1) {
      cout << v[i >> 1] << '\n';
    }
  }
  return 0;
}
