#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 1010;
int r[N], has[N], n;
char c[N];

inline int round(int x) {
  if (x <= 0) return x + n;
  if (x > n) return x - n;
  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t, m, x;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x;
    for (int i = 1; i <= m; ++i) cin >> r[i] >> c[i];
    queue<int> q;
    q.push(x);
    memset(has, 0, sizeof(has));
    for (int i = 1; i <= m; ++i) {
      int size = q.size();
      for (int j = 1; j <= size; ++j) {
        int cur = q.front(), to;
        q.pop();
        to = round(cur + r[i]);
        if ((c[i] == '0' || c[i] == '?') && has[to] != i) {
          q.push(to);
          has[to] = i;
        }
        to = round(cur - r[i]);
        if ((c[i] == '1' || c[i] == '?') && has[to] != i) {
          q.push(to);
          has[to] = i;
        }
      }
    }
    int size = q.size(), last = 0;
    for (int i = 1; i <= size; ++i) {
      int cur = q.front();
      q.pop();
      if (has[cur] != -1) {
        has[cur] = -1;
        r[++last] = cur;
        for (int j = last - 1; j >= 1; --j) {
          if (r[j] > r[j + 1])
            swap(r[j], r[j + 1]);
          else
            break;
        }
      }
    }
    cout << last << '\n';
    for (int i = 1; i <= last; ++i) cout << r[i] << ' ';
    cout << '\n';
  }
  return 0;
}
