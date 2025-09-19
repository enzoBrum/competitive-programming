#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;
ll INFL = 1e18;

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

    vector<int> prefix(n+1);
    for (int i = 1; i <= n; ++i)
      prefix[i] = prefix[i-1] + vec[i-1];

    bool suc = false;
    for (int l = 1; l < n && !suc; ++l) {
      for (int r = l+1; r < n && !suc; ++r) {
        int first = prefix[l] % 3;
        int middle = (prefix[r] - prefix[l]) % 3;
        int end = (prefix[n] - prefix[r]) % 3;

        if ((first == middle && first == end) || (first != middle && first != end && middle != end)) {
          cout << l << ' ' << r << '\n';
          suc = 1;
        }
      }
    }

    if (!suc)
      cout << "0 0\n";    
  }
}
