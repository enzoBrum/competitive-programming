#include <algorithm>
#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(s) std::cout << s << '\n';
#endif

using namespace std;
using pii = pair<int, int>;
using ll = long long;

static array<array<int, 602>, 602> adj, capacity;
static array<array<int, 301>, 301> matrix;
static array<pii, 602> st;
static array<int, 301> cnt, minimum_v;
static array<int, 602> sz, parent;

int top = 0;
int N;

int dfs(int s, int t) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;

  top = 0;
  st[top++] = {s, 1e9};
  while (top >= 0) {
    auto &[u, flow] = st[--top];

    for (int j = 0; j < sz[u]; ++j) {
      int v = adj[u][j];
      if (parent[v] == -1 && capacity[u][v]) {
        parent[v] = u;
        int new_flow = min(flow, capacity[u][v]);

        if (v == t)
          return new_flow;
        st[top++] = {v, new_flow};
      }
    }
  }

  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  int new_flow;

  while ((new_flow = dfs(s, t)) > 0) {
    flow += new_flow;
    int cur = t;

    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  unordered_map<string, int> mp_ai;
  unordered_map<int, string> mp_ia;

  cin >> N;

  fill(minimum_v.begin(), minimum_v.end(), N + 1);
  for (int i = 1; i <= N; ++i) {
    string id;
    cin >> id;
    mp_ai[id] = i;
    mp_ia[i] = id;
  }

  int r;
  cin >> r;
  for (int i = 0; i < r; ++i) {
    int m, w;
    cin >> m >> w;
    w--;

    cnt[w]++;
    for (int j = 0; j < m; ++j) {
      string id;
      cin >> id;

      int idx = mp_ai[id];

      minimum_v[idx] = max(minimum_v[idx], N + w + 1);
      matrix[idx][w]++;
    }
  }

  for (int i = 1; i <= N; ++i) {
    adj[0][sz[0]++] = i;
    adj[i][sz[i]++] = 0;
    capacity[0][i] = 1;
  }

  int last = 2 * N + 1;
  for (int i = N + 1; i < last; ++i) {
    adj[last][sz[last]++] = i;
    adj[i][sz[i]++] = last;
    capacity[i][last] = 1;
  }

  for (int i = 1; i <= N; ++i) {
    for (int p = minimum_v[i]; p < 2 * N + 1; ++p) {
      if (cnt[p - (N + 1)] != matrix[i][p - (N + 1)])
        continue;
      adj[i][sz[i]++] = p;
      adj[p][sz[p]++] = i;
      capacity[i][p] = 1;
    }
  }

  int x = maxflow(0, last);
  // cout << x << '\n';

  vector<string> ans(N);
  for (int i = 1; i <= N; ++i) {
    for (int j = minimum_v[i]; j < 2 * N + 1; ++j) {
      if (!capacity[i][j] && cnt[j - (N + 1)] == matrix[i][j - (N + 1)]) {
        ans[j - (N + 1)] = mp_ia[i];
      }
    }
  }

  for (auto &s : ans) {
    cout << s << ' ';
  }
  cout << '\n';
}
