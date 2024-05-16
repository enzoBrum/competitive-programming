#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll fast_exp(ll a, int b) {
  ll res = 1;
  while (b > 0) {
    if (b & 1)
      res *= a;
    a *= a;
    b >>= 1;
  }

  return res;
}

bool is_palindrome(ll n, int base) {
  ll n_digits = log(n) / log(base);

  ll l = 0, r = n_digits;

  while (l <= r) {
    ll lexp = fast_exp(base, l);
    ll rexp = fast_exp(base, r);

    ll l_digit = n % (lexp * base) / lexp;
    ll r_digit = n % (rexp * base) / rexp;

    // cout << "L=" << l << ",LD=" << l_digit << ",R=" << r << ",RD=" << r_digit
    //      << '\n';

    if (r_digit != l_digit)
      return false;

    l++;
    r--;
  }

  return true;
}

// Interesting how this problem only needs high school math.
// Sadly, it appears I am too dumb even for that.
// Maybe one day
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll n;
  cin >> n;

  int num = sqrt(n);

  for (int i = 2; i <= num; ++i) {
    if (n % i != 0 && is_palindrome(n, i)) {
      cout << i << ' ';
    }
  }

  int val = -1 + sqrt(1 + n);
  for (int d = val; d >= 1; --d)
    if (n % d == 0)
      cout << n / d - 1 << ' ';

  if (n <= 2)
    cout << "*\n";
}

