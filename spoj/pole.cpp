#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

const double EPS = 1e-9;

inline bool eq(double a, double b) { return abs(a - b) < EPS; }
inline bool eq(int a, int b) { return a == b; }

struct Point {
  double x, y;

  Point() : x{0}, y{0} {}
  Point(double x, double y) : x{x}, y{y} {}

  bool operator==(const Point &other) const {
    return eq(x, other.x) && eq(y, other.y);
  }

  bool operator<(const Point &other) const {
    return !eq(x, other.x) ? x < other.x : y < other.y;
  }
};

// y = ax + b
// nessa implementação, y = 0 para linhas verticais e y = 1 para o resto.
struct Line {
  double a, b, c;
  Line() : a{0}, b{0}, c{0} {}
  Line(double a, double b, double c) : a{a}, b{b}, c{c} {}
  Line(const Point &p1, const Point &p2) {
    if (eq(p1.x, p2.x)) {
      a = 1;
      b = 0;
      c = -p1.x;
    } else {
      a = (p1.y - p2.y) / (p1.x - p2.x);
      b = 1.0;
      c = -a * p1.x - p1.y;
    }
  }
  Line(const Point &p, double slope) : a{-slope}, b{1.0} {
    c = -((a * p.x) + (b * p.y));
  }

  bool operator==(const Line &l1) const {
    return eq(l1.a, a) && eq(l1.b, b) && eq(l1.c, c);
  }
};

bool inline parallel(const Line &l1, const Line &l2) {
  return eq(l1.a, l2.a) && eq(l1.b, l2.b);
}

// TODO: use std::optional. Only for c++17 and above
pair<Point, bool> find_intersection(const Line &l1, const Line &l2) {
  if (parallel(l1, l2))
    return {Point(), false};

  // y1 = ax + c
  // y2 = bx + d
  // y1 = y2
  // ax + c = bx + d
  // ax - bx = d - c
  // x = (d-c)/(a-b)
  // y = a(d-c)/(a-b) + c

  Point p;
  p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  p.y = abs(l1.b) > EPS ? -(l1.a * p.x + l1.c) : -(l2.a * p.x + l2.c);

  return {p, true};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
