#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;

int main() {
  LL a, b;
  cin >> a >> b;
  int ans = pow(a, b) + pow(b, a);
  cout << ans;
  return 0;
}
