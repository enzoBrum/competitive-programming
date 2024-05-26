#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using pii = pair<int, int>;
using ll = long long;

bool possible(vector<ll> &popcorn, int c, ll max_t, ll t) {
  ll curr_t = 0;
  int curr_c = 0;

  for (auto &p : popcorn) {
    if (curr_t * t + p * t > max_t) {
      if (curr_c == c)
        return false;
      curr_c++;
      curr_t = p * t;
    } else {
      curr_t += p * t;
    }
  }

  if (curr_t * t > max_t || curr_c >= c)
    return false;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, c, t;
  cin >> n >> c >> t;

  vector<ll> popcorn(n);
  for (auto &p : popcorn) {
    ll tmp;
    cin >> tmp;
    p = tmp;
  }

  ll max_t = accumulate(popcorn.begin(), popcorn.end(), 0ll) * t;

  ll k = 0;
  for (ll b = max_t; b >= 1; b /= 2) {
    while (!possible(popcorn, c, k + b, t))
      k += b;
  }

  cout << k + 1 << '\n';
}
