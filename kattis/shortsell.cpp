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

  int n, k;
  cin >> n >> k;

  int ans = 0, cur = 0;

  while (n--) {
    int num;
    cin >> num;

    if (num * 100 > cur)
      cur = num * 100;
    cur -= k;

    ans = max(ans, cur - num * 100);
  }
  cout << ans << '\n';
}
