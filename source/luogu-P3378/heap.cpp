#include <iostream>
using namespace std;

const int N = 1e6 + 5;
int value[N], idx = 0;

inline void up(int n) {
  int cur = n >> 1;
  while (cur != 0 && value[cur] > value[n]) {
    swap(value[cur], value[n]);
    n >>= 1; cur = n >> 1;
  }
}
inline void down(int n) {
  int l = n << 1, r = l + 1, t = n;
  // 如果两个都可以 swap，那么选择更大的那个
  if (l <= idx && value[t] > value[l]) t = l;
  if (r <= idx && value[t] > value[r]) t = r;
  if (t != n) {
    swap(value[n], value[t]);
    down(t);
  }
}
inline int top() {
  return value[1];
}
inline void push(int x) {
  value[++idx] = x;
  up(idx);
}
inline void pop() {
  swap(value[1], value[idx--]);
  down(1);
}

int main() {
  int n, op, x;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &op);
    switch (op) {
      case 1:
        scanf("%d", &x);
        push(x);
        break;
      case 2:
        printf("%d\n", top());
        break;
      case 3:
        pop();
        break;
    }
  }
  return 0;
}
