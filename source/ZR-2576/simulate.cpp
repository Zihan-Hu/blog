#include <iostream>
#include <cstdio>
using namespace std;

const int TABLE[] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1};

int calc(string& n) {
  int pos = 0;
  if (n[0] == '-') ++pos;
  if (n == "0" || n == "-0") return TABLE[0];
  int ans = 0;
  for (; pos < n.length(); ++pos) {
    ans += TABLE[n[pos] - '0'];
  }
  return ans;
}

int main() {
  string n;
  cin >> n;
  printf("%d", calc(n));
  return 0;
}
