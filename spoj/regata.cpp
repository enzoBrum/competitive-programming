#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

const double EPS = 1e-9;

inline bool eq(int a, int b) { return a == b; }

inline bool eq(double a, double b) { return abs(a - b) > 1e-6; }

template <typename T> struct Point {
  T x, y;
  Point(T xx, T yy) : x{xx}, y{yy} {}
  Point() : x{0}, y{0} {}

  bool operator==(const Point<T> &other) const {
    return eq(x, other.x) && eq(y, other.y);
  }
  bool operator<(Point<T> &other) {
    return eq(x, other.x) ? y < other.y : x < other.x;
  }
  bool operator>(Point<T> &other) {
    return eq(x, other.x) ? y > other.y : x > other.x;
  }

  friend istream &operator>>(istream &stream, Point<T> &p) {
    stream >> p.x >> p.y;
    return stream;
  }
};

template <typename T> double distance(Point<T> &a, Point<T> &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

template <typename T> struct Line {
  double a, b, c;
  Point<T> p1, p2;

  Line(Point<T> &A, Point<T> &B) {
    p1 = A, p2 = B;
    if (p1 > p2)
      swap(p1, p2);
    if (eq(A.x, B.x)) {
      a = 1.0;
      b = 0.0;
      c = -A.x;
    } else {
      a = -(double)(A.y - B.y) / (A.x - B.x);
      b = 1.0;
      c = -(double)(a * A.x) - A.y;
    }
  }

  bool are_parallel(const Line<T> &other) const {
    return eq(a, other.a) && eq(b, other.b);
  }

  bool operator==(const Line<T> &other) const {
    return p1 == other.p1 && p2 == other.p2;
  }

  bool intersection(const Line<T> &other) const {

    Point<double> p;
    p.x = (other.b * c - b * other.c) / (other.a * b - a * other.b);
    p.y = abs(b) > EPS ? -(a * p.x + c) : -(other.a * p.x + other.c);

    double min_y = min(p1.y, p2.y), max_y = max(p1.y, p2.y);
    if (p.x < p1.x || p.x > p2.x || p.y < min_y || p.y > max_y)
      return false;
    min_y = min(other.p1.y, other.p2.y), max_y = max(other.p1.y, other.p2.y);
    if (p.x < other.p1.x || p.x > other.p2.x || p.y < min_y || p.y > max_y)
      return false;

    return true;
  }
};

double dijkstra(vector<vector<pair<double, int>>> &adj) {
  vector<double> d(adj.size(), 1e9);
  priority_queue<pair<double, int>, vector<pair<double, int>>,
                 greater<pair<double, int>>>
      pq;

  d[0] = 0;
  pq.push({0, 0});

  while (!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();

    if (w > d[u])
      continue;

    for (auto &[wv, v] : adj[u]) {
      if (d[u] + wv > d[v])
        continue;

      d[v] = d[u] + wv;
      pq.push({d[v], v});
    }
  }

  return d.back();
}

bool has_intersection(int ignore, Line<int> &l1, vector<Line<int>> &lines,
                      int ignore2 = -2) {
  for (int i = 0; i < lines.size(); ++i)
    if (i != ignore && i != ignore2)
      if (l1.intersection(lines[i]))
        return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int xi, yi, xf, yf, n;
  while (cin >> xi >> yi >> xf >> yf >> n && (xi || yi || xf || yf || n)) {
    Point<int> p_begin(xi, yi), p_end(xf, yf);
    Line<int> curr(p_begin, p_end);

    vector<Line<int>> lines;
    for (int i = 0; i < n; ++i) {
      Point<int> p1, p2;
      cin >> p1 >> p2;
      lines.emplace_back(p1, p2);
    }

    vector<vector<pair<double, int>>> adj(n * 2 + 2);
    double ans = -1e9;

    if (!has_intersection(-1, curr, lines)) {
      ans = distance(curr.p1, curr.p2);
      cout << ans << '\n';
      continue;
    } else {
      for (int i = 0; i < lines.size(); ++i) {
        Line<int> l1(p_begin, lines[i].p1), l2(p_begin, lines[i].p2);
        if (!has_intersection(i, l1, lines)) {
          double d = distance(l1.p1, l1.p2);
          adj[0].push_back({d, i + 1});
          adj[i + 1].push_back({d, 0});
        }
        if (!has_intersection(i, l2, lines)) {
          double d = distance(l2.p1, l2.p2);
          adj[0].push_back({d, i + 2});
          adj[i + 2].push_back({d, 0});
        }
      }
    }

    int sz = n * 2 + 1;
    for (int i = 0; i < lines.size(); ++i) {
      Line<int> l_end1(lines[i].p1, p_end), l_end2(lines[i].p2, p_end);
      if (has_intersection(i, l_end1, lines)) {
        double d = distance(lines[i].p1, p_end);
        adj[i + 1].push_back({d, sz});
        adj[sz].push_back({d, i + 1});
      }
      if (has_intersection(i, l_end2, lines)) {
        double d = distance(lines[i].p2, p_end);
        adj[i + 2].push_back({d, sz});
        adj[sz].push_back({d, i + 2});
      }

      for (int j = 0; j < i; ++j) {
        if (j == i)
          continue;

        Line<int> l1(lines[i].p1, lines[j].p1), l2(lines[i].p1, lines[j].p2),
            l3(lines[i].p2, lines[j].p1), l4(lines[i].p2, lines[j].p2);
        if (has_intersection(i, l1, lines, j)) {
          double d = distance(l1.p1, l1.p2);
          adj[i + 1].push_back({d, j + 1});
          adj[j + 1].push_back({d, i + 1});
        }
        if (has_intersection(i, l2, lines, j)) {
          double d = distance(l2.p1, l2.p2);
          adj[i + 1].push_back({d, j + 2});
          adj[j + 2].push_back({d, i + 1});
        }
        if (has_intersection(i, l3, lines, j)) {
          double d = distance(l3.p1, l3.p2);
          adj[i + 2].push_back({d, j + 1});
          adj[j + 1].push_back({d, i + 2});
        }
        if (has_intersection(i, l4, lines, j)) {
          double d = distance(l4.p1, l4.p2);
          adj[i + 2].push_back({d, j + 2});
          adj[j + 2].push_back({d, i + 2});
        }
      }
    }

    ans = dijkstra(adj);
    cout << fixed << setprecision(2) << ans << '\n';
  }
}
