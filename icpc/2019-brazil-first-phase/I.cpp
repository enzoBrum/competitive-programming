#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(s) std::cout << s << '\n';
#endif

using namespace std;
using pii = pair<int, int>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, r;
  cin >> n >> r;

  vector<int> temps(n);
  set<int> st;

  vector<vector<vector<int>>> matrix_cold(
      n + 1, vector<vector<int>>(n, vector<int>(n, 1e9))),
      matrix_hot(n, vector<vector<int>>(n + 1, vector<int>(n, 1e9)));

  vector<pii> planets_ordered_by_temp(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    temps[i] = t;
    planets_ordered_by_temp[i] = {t, i};
    st.insert(t);
  }
  vector<int> ordered_unique_temps;
  for (auto &t : st)
    ordered_unique_temps.push_back(t);

  sort(planets_ordered_by_temp.begin(), planets_ordered_by_temp.end());

  for (int i = 0; i < r; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    matrix_hot[0][x][y] = matrix_hot[0][y][x] = matrix_cold[0][x][y] =
        matrix_cold[0][y][x] = w;
  }

  for (int k = 0; k < n; ++k)
    for (int u = 0; u < n; ++u)
      for (int v = 0; v < n; ++v)
        matrix_cold[k + 1][u][v] =
            min(matrix_cold[k][u][v],
                matrix_cold[k][u][planets_ordered_by_temp[k].second] +
                    matrix_cold[k][planets_ordered_by_temp[k].second][v]);
  for (int k = 0; k < n; ++k)
    for (int u = 0; u < n; ++u)
      for (int v = 0; v < n; ++v)
        matrix_hot[k + 1][u][v] = min(
            matrix_hot[k][u][v],
            matrix_hot[k][u][planets_ordered_by_temp[n - k - 1].second] +
                matrix_hot[k][planets_ordered_by_temp[n - k - 1].second][v]);

  int q;
  cin >> q;
  while (q--) {
    int a, b, k, t;
    cin >> a >> b >> k >> t;
    a--;
    b--;

    int ans = 1e9;
    if (t == 0)
      ans = matrix_cold[k][a][b];
    else
      ans = matrix_hot[k][a][b];

    cout << (ans == 1e9 ? -1 : ans) << '\n';
  }
}
