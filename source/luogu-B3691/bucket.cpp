#include <cstdio>
using namespace std;

const int N = 5e5 + 10, M = 5e6 + 10;
const int NULL_FLAG = -1;  // 表示此位置不存在值（被切割）
int a[N], b[N];
bool cnt[M];  // a 中有的值映射为 true，否则为 false
bool seg[M];  // a 和 b 中都有的值映射为 true，否则为 false

/**
 * 进行**狠狠地切割**。
 * @param arr 需要切割的数组（有效值的下标请从 1 开始）
 * @param end 有效值结束的下标
 * @return 片段数量
 */
int cut(int arr[], int end) {
  int ret = 0;
  // 第一个值被切割不会结束一个片段
  arr[0] = NULL_FLAG;
  for (int i = 1; i <= end; ++i) {
    if (seg[arr[i]]) {
      arr[i] = NULL_FLAG;
      // 上一个没有被切割，则此处结束了一个片段，记为新的片段
      if (arr[i - 1] != NULL_FLAG) ++ret;
    }
  }
  // 要记上最后一个片段
  // 但如果最后一个值被切割，那么这个片段已经被统计过了
  /**
   * @example
   * ```
   * 1 2 6 5 ==> 1 2 | 5
   * 9 8 6 7 ==> 9 8 | 7
   * ```
   * ```
   * 1 2 6 6 ==> 1 2 | |
   * 9 8 6 7 ==> 9 8 | 7
   * ```
   */
  ret += arr[end] != NULL_FLAG;
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &b[i]);
    // 原为 seg[b[i]] = (b[i] 在 b 中) && (b[i] 在 a 中)
    // b[i] 字面意思就是 b 中下标为 i 的值了，所以 b[i] 一定在 b 中
    // 所以简化为 seg[b[i]] = (在 a 中)
    seg[b[i]] = cnt[b[i]];
  }
  printf("%d", cut(a, n));
  return 0;
}
