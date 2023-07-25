#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef unsigned long long ULL;

/** 阶乘。 */
inline ULL factorial(int n) {
  return n != 0 ? tgamma(n + 1) : 1;
}
inline ULL calcA(int n, int m) {
  return factorial(n) / factorial(n - m); // n! / (n - m)!
}
inline ULL calcC(int n, int m) {
  return factorial(n) / (factorial(m) * factorial(n - m)); // n! / (m! * (n-m)!)
}

int main() {
  int n, m;
  cin >> n >> m;
  ULL a = calcA(n + 2, n + 2) * calcA(m, m) * calcC(n + 3, m);
  ULL b = calcA(2, 2) * calcA(n + 1, n + 1) * calcA(m, m) * calcC(n + 2, m);
  cout << a - b;
  return 0;
}
