#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (auto &v : vec)
      cin >> v;

    ull curr_max = vec[0];
    ull ans = 0;
    ull curr_sum = vec[0];

    for (int i = 1; i < n; ++i) {
      curr_sum += vec[i];
      if (vec[i] > curr_max)
        curr_max = vec[i];

      if (curr_sum - curr_max == curr_max)
        ans++;
    }

    if (vec[0] == 0)
      ans++;

    cout << ans << '\n';
  }
}
