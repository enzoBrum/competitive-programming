#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<char> ans(n);
  vector<int> exit_idx(n);

  vector<int> enter_idx(n);

  for (int i = 0; i < 2 * n; ++i) {
    char c;
    cin >> c;
    int num;
    cin >> num;
    num--;

    if (c == '+') {
      enter_idx[num] = i;
    } else {
      exit_idx[num] = i;
    }
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      if ((enter_idx[i] < enter_idx[j] && exit_idx[i] < exit_idx[j] &&
           exit_idx[i] > enter_idx[j]) ||
          (enter_idx[j] < enter_idx[i] && exit_idx[j] < exit_idx[i] &&
           exit_idx[j] > enter_idx[i]))
        adj[i].push_back(j), adj[j].push_back(i);

  int UNVISITED = 2;
  int G = 1;
  int S = 0;
  vector<int> color(n, UNVISITED);
  for (int i = 0; i < n; ++i) {
    if (color[i] != UNVISITED)
      continue;

    queue<int> q;
    q.push(i);
    color[i] = G;

    // cout << "COLOR[" << i << "]=" << G << '\n';
    while (!q.empty()) {
      auto u = q.front();
      q.pop();

      for (auto &v : adj[u]) {
        if (color[v] == color[u]) {
          cout << "*\n";
          return 0;
        } else if (color[v] == UNVISITED) {
          color[v] = 1 - color[u];
          // cout << "COLOR[" << v << "]=" << 1 - color[u] << '\n';
          q.push(v);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i)
    cout << (color[i] == G ? 'G' : 'S');
}
