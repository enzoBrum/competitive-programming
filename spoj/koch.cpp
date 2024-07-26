#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

// 1, 1, 2, 3, 5, 8
int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);

  int t;
  cin >> t;

  vector<int> last_three_fib = {0, 1, 1};
  for (int i = 0; i < 1497; ++i)
    last_three_fib.push_back(
        (*last_three_fib.rbegin() + *next(last_three_fib.rbegin())) % 1000);
  while (t--) {
    string k;
    cin >> k;

    int cur_idx = 0;
    for (int i = 0; i < k.size(); ++i) {
      cur_idx = (10 * cur_idx + (k[i] - '0')) % last_three_fib.size();
    }
    cout << setw(3) << setfill('0') << last_three_fib[cur_idx] << '\n';
  }
}
