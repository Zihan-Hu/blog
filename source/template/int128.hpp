#pragma once

// 限制只能使用 64 位编译器，因为 32 位编译器没 `__int128`
static_assert(sizeof(void *) == 8, "Only 64-bit platforms are supported.");

#include <iostream>

/**
 * 从 stdin 输入一个 `__int128` 数值。
 * @return 输入的数值
 */
__int128 scan() {
  __int128 ans = 0;
  bool sign = 0;
  char c = getchar();
  if (c == '-') {
    sign = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return (sign ? -ans : ans);
}

/**
 * 把一个 `__int128` 输出到 stdout。
 * @param n 输出的数值
 */
void print(__int128 n) {
  if (n < 0) {
    std::cout << '-';
    n = -n;
  }
  if (n > 9) print(n / 10);
  std::cout << int(n % 10);
}
