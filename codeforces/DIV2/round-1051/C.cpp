#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using iii = tuple<int, int, int>;

int INF = 1e9;

vector<vector<iii>> adj;
vector<pii> bound;
vector<int> ans;
vector<bool> used;
int n;

void dfs(int u, int p, int x, int y) {
  cout << "U " << u << ", P " << p << endl;
  for (auto&[v, vx, vy] : adj[u])
    dfs(v, u, vx, vy);

  auto[lo, hi] = bound[u];
  while (used[lo]) lo++;
  while (used[hi]) hi--;

  // cout << "LO " << lo << ", HI " << hi << ", U " << u <<  endl;
  assert(lo > 0 && lo <= n && hi > 0 && hi <= n && lo <= hi);

  if (x > y) {
    bound[p].first = max(bound[p].first, lo+1);
    used[lo] = 1;
    ans[u] = lo;
  } else {
    bound[p].second = min(bound[p].second, hi-1);
    ans[u] = hi;
    used[hi] = 1;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    adj.clear();
    bound.clear();
    used.clear();
    ans.clear();
    adj.resize(n+1);
    bound.assign(1+n, {1, n});
    used.assign(1+n, 0);
    ans.resize(n+1);

    for (int i = 0; i < n-1; ++i) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      adj[u].push_back({v, x, y});
    }

    for (int i = 1; i <= n; ++i)
      if (!ans[i]) {
        dfs(i, 0, -1, -1);
      }
    for (int i = 1; i <= n; ++i)
      cout << ans[i] << ' ';
    cout << endl;
  }
}
