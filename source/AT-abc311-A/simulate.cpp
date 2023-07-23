#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, ans;
  string s;
  cin >> n >> s;
  bool a = 0, b = 0, c = 0;
  for (ans = 0; ans < n; ++ans) {
    if (a && b && c) break;
    switch (s[ans]){
      case 'A': a = 1; break;
      case 'B': b = 1; break;
      case 'C': c = 1; break;
    }
  }
  cout << ans;
  return 0;
}
