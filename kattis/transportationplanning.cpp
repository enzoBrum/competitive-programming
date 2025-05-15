#include <bits/stdc++.h>
#include <csetjmp>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    vector<vector<double>> vec(n, vector<double>(n, 1e9));
    vector<vector<double>> d(n, vector<double>(n, 1e9));
    vector<vector<bool>> og_edges(n, vector<bool>(n, false));
    vector<pii> intersections(n);
    for (auto &[x, y] : intersections)
      cin >> x >> y;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        vec[i][j] = vec[j][i] =
            sqrt((intersections[i].first - intersections[j].first) *
                     (intersections[i].first - intersections[j].first) +
                 (intersections[i].second - intersections[j].second) *
                     (intersections[i].second - intersections[j].second));

    int m;
    cin >> m;
    while (m--) {
      int u, v;
      cin >> u >> v;
      d[u][v] = d[v][u] = vec[u][v];
      og_edges[u][v] = og_edges[v][u] = true;
    }
    for (int i = 0; i < n; ++i)
      d[i][i] = 0;

    for (int k = 0; k < n; ++k)
      for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
          d[u][v] = min(d[u][v], d[u][k] + d[k][v]);

    double og = 0;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        if (d[i][j] < 1e9)
          og += d[i][j];

    int uans, vans;
    double dans = og;
    for (int k = 0; k < n; ++k)
      for (int l = k + 1; l < n; ++l) {
        double curans = og;
        for (int i = 0; i < n; ++i)
          for (int j = i + 1; j < n; ++j)
            if (d[i][k] < 1e9 && d[l][j] < 1e9 && !og_edges[k][l] &&
                (d[i][j] >= 1e9 ||
                 curans - d[i][j] + d[i][k] + vec[k][l] + d[l][j] < curans))
              curans = curans - d[i][j] + d[i][k] + vec[k][l] + d[l][j];
        if (curans < dans)
          dans = curans, uans = k, vans = l;
      }

    if (abs(og - dans) < 1e-3)
      cout << fixed << setprecision(9) << "no addition reduces " << og << '\n';
    else
      cout << fixed << setprecision(9) << "adding " << uans << ' ' << vans
           << " reduces " << og << " to " << dans << '\n';
  }
}
