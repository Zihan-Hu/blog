#include <iostream>
#include <algorithm>
using namespace std;

const int N = 305;

struct Student {
  explicit Student(string name = "", int score = 0): name(name), score(score) {
    this->name.reserve(50);
  }
  string name;
  int score;
} p[N];

int main() {
  int n;
  while (cin >> n) {
    bool right = true, stable = true;
    for (int i = 1; i <= n; ++i) cin >> p[i].name >> p[i].score;
    stable_sort(p + 1, p + n + 1, [](Student a, Student b) {  // 使用稳定的排序
      return a.score > b.score;
    });
    Student p2;
    for (int i = 1; i <= n; ++i) {
      cin >> p2.name >> p2.score;
      if (!right) continue;  // 结果错误是最坏情况，无需再判
      if (p2.score != p[i].score)  // 排序关键字不相同，即为结果错误
        right = false;
      else if (p2.name != p[i].name)  // 名字不相同，即为不稳定
        stable = false;
    }
    if (right && stable) {
      cout << "Right\n";
    } else {
      cout << (right ? "Not Stable" : "Error") << '\n';
       // 输出正确结果
      for (int i = 1; i <= n; ++i) {
        cout << p[i].name << ' ' << p[i].score << '\n';
      }
    }
  }
  return 0;
}
