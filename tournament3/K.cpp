#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, w;
  cin >> n >> m >> w;

  vector<int> vec(n);
  for (auto& v : vec)
    cin >> v;

  vector<char> active(n, true);

  vector<int> ans(m+1);
  ans[0] = 0;
  for (int k = 1; k <= m; ++k) {
    int l = 0, r = l + w - 1;
    int best_l = 0, best_r = r;
    int sum = 0, best_sum = 0;

    for (int i = l; i <= r; ++i)
      if (active[i])
        sum += vec[i];

    best_l = l, best_r = r;
    best_sum = sum;
    for (int i = r+1; i < n; ++i) {
      if (active[l])
        sum -= vec[l];
      if (active[i])
        sum += vec[i];

      ++l;
      if (sum > best_sum) {
        best_l = l;
        best_r = i;
        best_sum = sum;
      }
    }

    ans[k] = ans[k-1] + best_sum;
    for (int i = best_l; i <= best_r; ++i)
      active[i] = false;
  }
  cout << *max_element(ans.begin(), ans.end()) << '\n';
}
