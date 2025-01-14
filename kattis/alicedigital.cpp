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

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n), prefix(n, 0);
    for (auto &v : vec)
      cin >> v;
    prefix[0] = vec[0];
    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] + vec[i];

    int ans = 0, cur = 0, last_m = -1;
    for (int i = 0; i < n; ++i) {
      int num = vec[i];

      if (num == m && last_m != -1)
        ans = max(ans, cur), cur = prefix[i] - prefix[last_m], last_m = i;
      else if (num < m)
        ans = last_m != -1 ? max(ans, cur) : ans, cur = 0, last_m = -1;
      else if (num == m && last_m == -1)
        cur += num, last_m = i;
      else
        cur += num;
    }

    cout << (last_m != -1 ? max(ans, cur) : ans) << '\n';
  }
}
