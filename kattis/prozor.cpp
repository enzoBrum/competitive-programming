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

  // n x m
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<char>> window(n, vector<char>(m, 0));
  for (auto &row : window)
    for (auto &cell : row)
      cin >> cell;

  int cur = 0;
  k -= 2;
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= k; ++j)
      if (window[i][j] == '*')
        cur++;

  int l = 1, r = k, u = 1, d = k;

  int ans = cur;
  int ans_l = l, ans_r = r, ans_u = u, ans_d = d;
  while (1) {
    int og_cur = cur;
    int og_l = l;
    int og_r = r;
    while (1) {
      for (int i = u; i <= d; ++i)
        if (window[i][l] == '*')
          cur--;
      l++;
      r++;

      if (r >= m - 1)
        break;

      for (int i = u; i <= d; ++i)
        if (window[i][r] == '*')
          cur++;
      if (cur > ans) {
        ans = cur;
        ans_l = l, ans_r = r, ans_u = u, ans_d = d;
      }
    }

    l = og_l;
    r = og_r;
    cur = og_cur;

    for (int j = l; j <= r; ++j)
      if (window[u][j] == '*')
        cur--;
    u++;
    d++;

    if (d >= n - 1)
      break;

    for (int j = l; j <= r; ++j)
      if (window[d][j] == '*')
        cur++;

    if (cur > ans) {
      ans = cur;
      ans_l = l, ans_r = r, ans_u = u, ans_d = d;
    }
  }

  cout << ans << '\n';
  ans_u--, ans_d++, ans_l--, ans_r++;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      bool i_edge = i == ans_u || i == ans_d;
      bool j_edge = j == ans_l || j == ans_r;

      char c;
      if (i_edge && j_edge)
        c = '+';
      else if (j_edge && i > ans_u && i < ans_d)
        c = '|';
      else if (i_edge && j > ans_l && j < ans_r)
        c = '-';
      else
        c = window[i][j];
      cout << c;
    }
    cout << '\n';
  }
}
