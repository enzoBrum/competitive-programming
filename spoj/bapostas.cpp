#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  while (cin >> n && n) {
    int ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;

      cur = num + cur < num ? num : num + cur;
      ans = max(ans, cur);
    }

    ans = max(ans, cur);

    if (ans > 0)
      cout << "The maximum winning streak is " << ans << ".\n";
    else
      cout << "Losing streak.\n";
  }
}
