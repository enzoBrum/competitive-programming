#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

int main() {
  ll n;
  cin >> n;

  ll ans = 1;
  while (n > 0) {
    if (n % 2 != 0)
      ans *= 2;
    n /= 2;
  }

  cout << ans << '\n';
}

