#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(s) std::cout << s << '\n';
#endif

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;
using ll = long long;
using ull = unsigned long long;

struct Point {
  double x, y;
  Point() : x{0}, y{0} {}
  Point(double x, double y) : x{x}, y{y} {}

  bool operator==(const Point &other) const {
    return abs(x - other.x) < 1e-6 && abs(y - other.y) < 1e-6;
  }

  // Three points are collinear if their slope is the same
  double slope(const Point &other) const {
    if (x == other.x)
      return 0; // infinite slope
    return (y - other.y) / (x - other.x);
  }
};

Point inline read_point() {
  double x, y;
  cin >> x >> y;
  return Point(x, y);
}

inline double distance(const Point &p1, const Point &p2) {
  double x = p1.x - p2.x, y = p1.y - p2.y;
  return sqrt(x * x + y * y);
}

// Returns point equidistant to all vertices of the triangle
Point circuncenter(Point &A, Point &B, Point &C) {

  // LINE AB
  // ax + by = c
  double a = B.y - A.y, b = A.x - B.x;
  double c = a * A.x + b * A.y;

  // LINE BC
  double e = C.y - B.y, f = B.x - C.x;
  double g = e * B.x + f * B.y;

  // convert AB to perpendicular bisector
  c = -b * (A.x + B.x) / 2 + a * (A.y + B.y) / 2;
  b = exchange(a, -b);

  // convert BC to perpendicular bisector
  g = -f * (B.x + C.x) / 2 + e * (B.y + C.y) / 2;
  f = exchange(e, -f);

  double determinant = a * f - e * b;
  if (determinant == 0)
    return Point(1e9, 1e9);
  return Point((f * c - b * g) / determinant, (a * g - e * c) / determinant);
}

bool collinear(Point &p1, Point &p2, Point &p3) {
  double s12 = p1.slope(p2), s13 = p1.slope(p3), s23 = p2.slope(p3);
  return abs(s12 - s13) < 1e-8 && abs(s12 - s23) < 1e-8;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  while (n--) {
    Point p1, p2, p3;

    p1 = read_point();
    p2 = read_point();
    p3 = read_point();

    if (p1 == p2 || p1 == p3 || p2 == p3) {
      cout << "There is an infinity of possible locations.\n";
    } else if (collinear(p1, p2, p3)) {
      cout << "There is no possible location.\n";
    } else {
      Point center = circuncenter(p1, p2, p3);

      cout << "The equidistant location is (" << fixed << setprecision(7)
           << center.x << ", " << center.y << ").\n";
    }
  }
}
