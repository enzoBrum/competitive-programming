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
  while (cin >> n && n) {
    vector<int> p(n, -1);
    vector<int> lis(n, 1e9);
    vector<int> lis_idx(n, 1e9);
    vector<int> vec(n);
    int k = 0;

    for (auto &v : vec)
      cin >> v;

    for (int i = 0; i < n; ++i) {
      int pos = lower_bound(lis.begin(), lis.begin() + k, vec[i]) - lis.begin();

      lis[pos] = vec[i];
      lis_idx[pos] = i;
      p[i] = pos ? lis_idx[pos - 1] : -1;

      if (pos == k)
        ++k;
    }

    cout << k << ' ';

    vector<int> seq;
    seq.push_back(lis[k - 1]);

    int cur = p[lis_idx[k - 1]];
    while (cur != -1) {
      seq.push_back(vec[cur]);
      cur = p[cur];
    }
    for (auto it = seq.rbegin(); it != seq.rend(); ++it)
      cout << *it << ' ';
    cout << '\n';
  }
}
