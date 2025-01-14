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

  vector<int> lis(n, -1), lds(n, -1);
  vector<int> lis_sz(n, -1), lds_sz(n, -1);
  int kis = 0, kds = 0;

  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  for (int i = n - 1; i >= 0; --i) {
    int num = vec[i];
    int pos = lower_bound(lis.begin(), lis.begin() + kis, num) - lis.begin();

    if (pos == kis)
      kis++;
    lis[pos] = num;
    lis_sz[i] = pos + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    int num = vec[i];
    int pos = lower_bound(lds.begin(), lds.begin() + kis, num, greater<int>()) -
              lds.begin();

    if (pos == kis)
      kis++;
    lds[pos] = num;
    lds_sz[i] = pos + 1;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, lds_sz[i] + lis_sz[i] - 1);
  cout << ans << '\n';
}
