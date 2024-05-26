#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include<map>
using namespace std;
using ll = long long;
using pii = pair<int, int>;


struct SparseTable {
  vector<vector<pii>> st;
  int k = 25;
  int n;

  SparseTable(const vector<pii>& vec) {
    n = vec.size();
    st.assign(k+1, vector<pii>(n));
    st[0] = vec;
     
    for (int i = 1; i <= k; ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        st[i][j] = max(st[i-1][j], st[i-1][j + (1 << (i-1))]);
  }

  pii query(int l, int r) {
    if (l == r)
      return st[0][l];
    
    int i = log2((unsigned long) (r - l + 1)) - 1; // change to log2 and memoization if c++20 is not available.
    return max(st[i][l], st[i][r - (1 << i) + 1]);
  }
};


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> dist(n+1);
  for (int i = 1; i <= n; ++i)
    cin >> dist[i];

  vector<int> tob(n+1);
  for (int i = 1; i <= n; ++i)
    cin >> tob[i];

  vector<int> pref(n+1);

  dist[0] = 0;
  tob[0] = k;
  pref[0] = dist[0];
  for (int i = 1; i <= n; ++i)
    pref[i] = dist[i];

  vector<pii> sum(n);
  for (int i = 0; i <= n; ++i)
    sum[i] = {tob[i]+pref[i], i};

  SparseTable st(sum);

  int curr = 0;
  int ans = 0;
  while (curr < n) {
    int r = prev(upper_bound( pref.begin(), pref.end(), pref[curr] + k )) - pref.begin();

    if (r == n) break;
    if (r == curr) {
      ans = -1;
      break;
    }

    auto[val, idx] = st.query(curr+1, r);

    k = tob[idx];
    curr = idx;
    ans++;
  }

  cout << ans << '\n';
}