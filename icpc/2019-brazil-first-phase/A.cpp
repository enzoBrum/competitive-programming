#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(s) std::cout << s << '\n';
#endif

using namespace std;
using pii = pair<int, int>;

struct Circle {
  int x, y, r;
};

inline bool is_inside(Circle &a, Circle &b) {
  double d = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));

  return d <= a.r + b.r || d <= a.r - b.r || d <= b.r - a.r;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int m, n, k;
  cin >> m >> n >> k;

  vector<vector<int>> adj(k);
  vector<Circle> sensors(k);

  vector<vector<bool>> matrix(k, vector<bool>(k, false));
  for (int i = 0; i < k; ++i) {
    int x, y, tmp;
    cin >> x >> y >> tmp;

    Circle c;
    c.r = tmp;
    c.x = x;
    c.y = y;
    sensors[i] = c;
  }

  for (int i = 0; i < k; ++i) {
    Circle &c1 = sensors[i];
    for (int j = 0; j < i; ++j) {
      Circle &c2 = sensors[j];
      if (is_inside(c1, c2) && !matrix[i][j]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
        matrix[i][j] = matrix[j][i] = true;
      }
    }
  }

  // for (int i = 0; i < k; ++i)
  //   for (auto &v : adj[i])
  //     cout << i << ' ' << v << endl;

  bool success = true;
  vector<bool> visited(k, false);
  for (int i = 0; i < k; ++i) {
    visited[i] = true;

    bool left = false, right = false, up = false, down = false;
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int u = q.front();
      q.pop();

      Circle &c = sensors[u];
      if (c.x - c.r <= 0)
        left = true;
      if (c.x + c.r >= m)
        right = true;
      if (c.y + c.r >= n)
        up = true;
      if (c.y - c.r <= 0)
        down = true;

      for (auto &v : adj[u]) {
        if (visited[v])
          continue;
        visited[v] = true;
        q.push(v);
      }
    }

    if (left && right)
      success = false;
    if (up && down)
      success = false;
    // if (left && up)
    //   success = false;
    if (right && up)
      success = false;
    if (left && down)
      success = false;

    if (!success)
      break;
  }

  cout << (success ? "S\n" : "N\n");
}

