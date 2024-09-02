#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> vec(n);
  for (auto& v : vec)
    cin >> v;
  int q;
  cin >> q;

  vector<vector<int>> memo(1e4, vector<int>(1e4, 1e9));
  


  for (int i = 1; i < vec.size(); ++i) {
    int ans = 1e9;
    for (int j = i-1; j >= 0; --j) {
      ans = min(ans, abs(vec[i] - vec[j]));
      ans = min(ans, memo[i-1][j]);
      memo[i][j] = ans;
    }
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << memo[r][l] << '\n';
  }
}
