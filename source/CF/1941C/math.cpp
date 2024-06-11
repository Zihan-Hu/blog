#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 10;

int count(const string& str, const string& sub) {
  int pos = -1, ret = 0;
  while (1) {
    pos = str.find(sub, pos + 1);
    if (pos == str.npos) break;
    ++ret;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t, n, ans;
  string s;
  cin >> t;
  s.reserve(N);
  while (t--) {
    cin >> n >> s;
    cout << count(s, "map") + count(s, "pie") - count(s, "mapie") << '\n';
  }
  return 0;
}
