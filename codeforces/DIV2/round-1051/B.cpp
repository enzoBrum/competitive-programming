#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    
    vector<ll> vec(n), vouchers(k);
    for (auto& v : vec)
      cin >> v;
    for (auto& v : vouchers)
      cin >> v;

    sort(all(vouchers));
    sort(rall(vec));

    ll ans = 0;
    int vec_idx = 0;
    int voucher_idx = 0;

    while (vec_idx < n) {
      if (voucher_idx == k) {
        ans += vec[vec_idx++];
        // cout << "VEC " << vec[vec_idx-1] << '\n';
        continue;
      }
      
      int cur_voucher = vouchers[voucher_idx++];
      for (int i = 0; i < cur_voucher-1 && vec_idx < n; ++i) {
        ans += vec[vec_idx++];
        // cout << "VEC " << vec[vec_idx-1] << '\n';
      }

      vec_idx++;
      
    }

    cout << ans << '\n';
  }
}
