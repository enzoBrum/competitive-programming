#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int k, n, m;
  cin >> k >> n >> m;

  vector<vector<vector<pii>>> adj(n, vector<vector<pii>>(k));
  vector<vector<int>> passangers(n + 1, vector<int>(k, 0));

  while (m--) {
    int u, v, d, z;
    cin >> u >> v >> d >> z;
    adj[--d][--u].push_back({z, --v});
  }

  for (int i = 0; i < k * n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    passangers[--b][--a] += c;
  }

  bool suc = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k && suc; ++j) {
      for (auto &[z, v] : adj[i][j]) {
        if (passangers[i][j] < z) {
          suc = false;
          break;
        }
        passangers[i][j] -= z;
        passangers[i + 1][v] += z;
      }
    }

    if (!suc)
      break;

    for (int j = 0; j < k; ++j)
      passangers[i + 1][j] += passangers[i][j];
  }

  cout << (suc ? "optimal\n" : "suboptimal\n");
}
