#include <iostream>
#include <cstdio>
using namespace std;

const int N = 20, M = 8;
char map[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 1; i <= M; ++i) scanf("%s", map[i] + 1);
    for (int i = 1; i <= M; ++i) for (int j = 1; j <= M; ++j) {
      char c = map[j][i];
      if (c != '.') printf("%c", c);
    }
    printf("\n");
  }
  return 0;
}
