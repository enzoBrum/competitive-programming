#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {
    {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2},
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    char cj, ci;
    cin >> cj >> ci;

    int kj = cj - 'a';
    int ki = 7 - (ci - '1');

    int INF = 1e9;
    vector<vector<int>> d(8, vector<int>(8, INF));

    d[ki][kj] = 0;
    using iiii = tuple<int, int, int, pii>;
    priority_queue<iiii> pq;

    pq.push({0, ki, kj, {-1, -1}});
    while (!pq.empty()) {
      auto [dd, i, j, pr] = pq.top();
      pq.pop();

      if (d[i][j] != dd)
        continue;
      for (auto &[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fi >= 8 || fj < 0 || fj >= 8 || d[fi][fj] < d[i][j] + 1)
          continue;
        d[fi][fj] = d[i][j] + 1;
        pq.push({d[fi][fj], fi, fj, {i, j}});
      }
    }

    int best_i = -1, best_j = -1, best = -1;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (d[i][j] > best)
          best = d[i][j], best_i = i, best_j = j;
    vector<pii> vec;
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j)
        if (d[i][j] == best)
          vec.push_back({i, j});

    cout << best << ' ';
    for (auto &cur : vec) {
      char r = '8' - cur.first;
      char c = 'a' + cur.second;
      cout << c << r << ' ';
    }
    cout << '\n';
  }
}
