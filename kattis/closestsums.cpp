#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  int t = 0;
  while (cin >> n) {
    vector<int> vec(n);
    for (auto& v : vec)
      cin >> v;
    sort(vec.begin(), vec.end());

    int m;
    cin >> m;
    cout << "Case " << ++t << ":\n";
    while (m--) {
      int q;
      cin >> q;

      int ans = 1e9, diff = 1e9;
      for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
          if (abs(vec[i] + vec[j] - q) < diff)
            ans = vec[i] + vec[j], diff = abs(vec[i] + vec[j] - q);
      
      cout << "Closest sum to " << q << " is " << ans << ".\n";
    }
  }
}
