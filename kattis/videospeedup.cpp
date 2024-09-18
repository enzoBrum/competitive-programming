#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, p, k;
  cin >> n >> p >> k;

  vector<int> ts(n);
  for (auto& t : ts)
    cin >> t;

  double ans = ts[0];
  ts.push_back(k);
  for (int i = 1; i < ts.size(); ++i)
    ans += (ts[i]-ts[i-1])*((100 + i*p)/100.0);
  cout << fixed << setprecision(6) << ans << '\n';
}
