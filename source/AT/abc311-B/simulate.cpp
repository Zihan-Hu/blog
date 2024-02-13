#include <iostream>
#include <string>
using namespace std;

const int N = 105;
bool busy[N];

int main() {
  int n, d;
  string s;
  cin >> n >> d;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 0; j < d; ++j) {
      if (s[j] == 'x') busy[j + 1] = 1;
    }
  }
  int ans = 0, cur = 0;
  for (int i = 1; i <= d; ++i) {
    if (busy[i]) {
      ans = max(ans, cur);
      cur = 0;
    } else {
      ++cur;
    }
  }
  ans = max(ans, cur);
  cout << ans;
  return 0;
}
