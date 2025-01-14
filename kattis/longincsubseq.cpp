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
  while (cin >> n) {
    vector<int> lis(n);
    vector<int> lis_idx(n);
    vector<int> vec(n);
    int k = 0;

    vector<int> p(n, -1);

    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
      int num = vec[i];

      int pos = lower_bound(lis.begin(), lis.begin() + k, num) - lis.begin();

      lis[pos] = num;
      lis_idx[pos] = i;

      p[i] = pos ? lis_idx[pos - 1] : -1;

      if (pos == k)
        k++;
    }

    if (!k) {
      cout << "0\n";
      continue;
    }

    vector<int> ans;
    ans.push_back(lis_idx[k - 1]);

    int cur = p[lis_idx[k - 1]];
    while (cur != -1)
      ans.push_back(cur), cur = p[cur];

    cout << k << '\n';
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
      cout << *it << ' ';
    cout << '\n';
  }
}
