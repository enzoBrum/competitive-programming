#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {{-1, 0}, {-1, 1}, {0, 1},  {1, 1},
                          {1, 0},  {1, -1}, {0, -1}, {-1, -1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, c;
  cin >> r >> c;

  vector<vector<char>> lake(r, vector<char>(c));
  for (auto &row : lake)
    for (auto &cell : row)
      cin >> cell;

  int q;
  cin >> q;

  int INF = 1e9;
  while (q--) {
    int rs, cs, rd, cd;
    cin >> rs >> cs >> rd >> cd;
    rs--, cs--, rd--, cd--;

    deque<tuple<int, int, int>> q;
    q.push_back({0, rs, cs});
    vector<vector<int>> d(r, vector<int>(c, INF));

    d[rs][cs] = 0;
    bool found = false;
    while (!q.empty() && !found) {
      auto [dd, i, j] = q.front();
      q.pop_front();

      if (i == rd && j == cd)
        break;

      for (auto &[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fi >= r || fj < 0 || fj >= c)
          continue;
        if (d[fi][fj] > d[i][j] &&
            directions[lake[i][j] - '0'] == (pii){di, dj})
          d[fi][fj] = d[i][j], q.push_front({d[i][j], fi, fj});
        else if (d[fi][fj] > d[i][j] + 1)
          d[fi][fj] = d[i][j] + 1, q.push_back({d[i][j] + 1, fi, fj});
        else
          continue;
      }
    }

    cout << d[rd][cd] << '\n';
  }
}
