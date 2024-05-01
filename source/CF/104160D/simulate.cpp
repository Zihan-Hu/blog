#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int t = 0, d = 0;
  for (char c : s) {
    switch (c) {
      case 'T': ++t; break;
      case 'D': ++d; break;
    }
    if (t >= 3) {
      cout << "T1";
      break;
    } else if (d >= 3) {
      cout << "DRX";
      break;
    }
  }
  return 0;
}
