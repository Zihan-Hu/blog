#include <iostream>
using namespace std;

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  for (int i = 1; i <= 8; ++i) {
    int n;
    cin >> n;
    if (n == 9) {
      cout << 'F';
      return 0;
    }
  }
  cout << 'S';
  return 0;
}
