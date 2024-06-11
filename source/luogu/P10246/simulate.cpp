#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ULL;
typedef pair<ULL, ULL> Date;

const ULL N = 3e5 + 10, LIM = 1e14;
int a[N];

vector<Date> getGreatDays(int n, int k) {
  vector<Date> ret;
  ULL num = 1, m, d, base;
  while (num <= LIM) {
    num *= k;
    if (num < 10) continue;  // 必须是两位数
    m = num;
    d = 0;
    base = 1;
    while (m) {
      // 注意前导零的检测
      if (m <= n && d >= 1 && d <= a[m] && d * 10 >= base) {
        ret.emplace_back(m, d);
      }
      d = m % 10 * base + d;
      m /= 10;
      base *= 10;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (k == 1) {  // 1^n = 1 会导致死循环
      cout << "0\n";
      continue;
    }
    vector<Date> ans = getGreatDays(n, k);
    sort(ans.begin(), ans.end(), [](Date& a, Date& b) {  // 按日期排序
      if (a.first != b.first) return a.first < b.first;
      return a.second <= b.second;
    });
    cout << ans.size() << '\n';
    for (Date& item : ans) {
      cout << item.first << ' ' << item.second << '\n';
    }
  }
  return 0;
}
