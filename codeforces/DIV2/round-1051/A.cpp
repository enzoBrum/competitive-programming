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
    int n;
    cin >> n;
    vector<int> vec(n);
    for (auto& v : vec)
      cin >> v;

    int gt_idx = max_element(all(vec)) - vec.begin();
    bool suc = 1;

    for (int k = 1; k <= n && suc; ++k) {
      // cout << "BEFORE\n";
      // for (auto& v : vec)
      //   cout << v << ' ';
      // cout << "\n";
      int cur_idx = gt_idx+1;
      int cnt = 0;
      while (cur_idx <= n - 1 && vec[cur_idx] == vec[gt_idx])
        vec[cur_idx++]--, cnt++;
      cur_idx = gt_idx-1;
      while (cur_idx>=0 && vec[cur_idx] == vec[gt_idx])
        vec[cur_idx--]--, cnt++; 
      
      vec[gt_idx]--;
      cnt++;

      if (cnt != k)
        suc = 0;

      // cout << "AFTER\n";
      // for (auto& v : vec)
      //   cout << v << ' ';
      // cout << "\n";
    }

    if (suc)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
