#include <climits>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef unsigned long long ULL;

const int N = 2e5 + 10;
int a[N];
bool good[N];
unordered_map<int, bool> contains;

int main() {
  int t, n, ans;
  ULL sum;
  cin >> t;
  a[0] = -1;
  good[0] = 1;
  while (t--) {
    cin >> n;
    ans = sum = 0;
    contains.clear();
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      contains[a[i]] = 1;
      sum += a[i];
      good[i] = 0;
      if (a[i] == 0) {
        if (good[i - 1]) {
          ++ans;
          good[i] = 1;
        }
        // clog << "[log] at " << i << ", skip as " << good[i - 1] << '\n';
        continue;
      }
      bool c1 = good[i - 1] && a[i] == sum - a[i],
           c2 = !good[i - 1] && sum % 2 == 0 && sum <= UINT_MAX &&
                contains[sum / 2];
      if (c1 || c2) {
        ++ans;
        good[i] = 1;
      }
      // clog << "[log] at " << i << ", " << c1 << c2 << '\n';
    }
    cout << ans << '\n';
  }
  return 0;
}
