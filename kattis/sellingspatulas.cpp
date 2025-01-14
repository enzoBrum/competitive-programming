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
    int ans = 0;
    int mbegin = 0, mend = 0;

    int last_m = -1;
    int cur = 0;
    int cur_mbegin = 0;
    while (n--) {
      int m;
      double buf;
      cin >> m >> buf;

      int profit = round(buf * 100);
      profit -= 8;

      cur += profit;
      if (last_m != -1)
        cur -= (m - last_m - 1) * 8;
      if (last_m == -1)
        cur_mbegin = m, cur -= m * 8;

      if (cur <= max(profit, 0))
        cur = max(profit, 0), cur_mbegin = m;

      if (cur < ans) {
        last_m = m;
        continue;
      }

      if (cur > ans || mend - mbegin > m - cur_mbegin) {
        ans = cur;
        mbegin = cur_mbegin;
        mend = m;
      }

      last_m = m;
    }
    // ans -= 8;

    auto num = to_string(ans);
    if (num.size() == 2)
      num.insert(num.begin(), '0');
    else if (num.size() == 1) {
      num.insert(num.begin(), '0');
      num.insert(num.begin(), '0');
    }
    num.insert(num.end() - 2, '.');
    if (ans > 0)
      cout << num << ' ' << mbegin << ' ' << mend << '\n';
    else
      cout << "no profit\n";
  }
}
