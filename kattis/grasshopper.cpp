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

  int r, c, gr, gc, lr, lc;
  while (cin >> r) {
    cin >> c >> gr >> gc >> lr >> lc;
    gr--, gc--, lr--, lc--;

    queue<pii> q;
    int INF = 1e9;
    vector<vector<int>> d(r, vector<int>(c, INF));
    d[gr][gc] = 0;
    q.push({gr, gc});

    bool found = false;
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();

      if (i == lr && j == lc) {
        cout << d[i][j] << '\n';
        found = true;
        break;
      }
      for (auto &[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fi >= r || fj < 0 || fj >= c || d[fi][fj] != INF)
          continue;
        d[fi][fj] = d[i][j] + 1;
        q.push({fi, fj});
      }
    }
    if (!found)
      cout << "impossible\n";
  }
}
