#include <iostream>
#include <cmath>
using namespace std;

/** 所处区域类型。 */
enum AreaType {
  FRONT = 1,  // 正面
  BACK,  // 反面
  LEFT,  // 左侧面
  RIGHT,  // 右侧面
  TOP,  // 上底面
  BOTTOM,  // 下底面
};

struct Point2 {
  explicit Point2(double x = 0, double y = 0): x(x), y(y) {}
  double x, y;
} p1, p2;
struct Point3 {
  explicit Point3(double x = 0, double y = 0, double h = 0): x(x), y(y), h(h) {}
  double x, y, h;
};

int a, b, c;

AreaType toAreaType(const Point2& p) {
  if (p.x < c) return AreaType::LEFT;
  if (p.x > a + c) return AreaType::RIGHT;
  if (p.y < b) return AreaType::TOP;
  if (p.y < b + c) return AreaType::FRONT;
  if (p.y > b + c + b) return AreaType::BACK;
  return AreaType::BOTTOM;
}
Point3 toPoint3(const Point2& p) {
  switch (toAreaType(p)) {
    case AreaType::FRONT: return Point3(p.x, b + c, c + b - p.y);
    case AreaType::BACK: return Point3(p.x, b + c + b, p.y - b - c - b);
    case AreaType::LEFT: return Point3(c, p.y, c - p.x);
    case AreaType::RIGHT: return Point3(c + a, p.y, p.x - c - a);
    case AreaType::TOP: return Point3(p.x, b + c + b - p.y, c);
    case AreaType::BOTTOM: return Point3(p.x, p.y, 0);
  }
  return Point3();
}

int main() {
  scanf("%d%d%d", &a, &b, &c);
  scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
  Point3 p3 = toPoint3(p1), p4 = toPoint3(p2);
  double x = abs(p3.x - p4.x), y = abs(p3.y - p4.y), h = abs(p3.h - p4.h);
  printf("%.2lf", sqrt(x * x + y * y + h * h));
  return 0;
}
