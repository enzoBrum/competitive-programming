#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string s;
  cin >> s;

  vector<int> roots;

  int first_h = s[0] == 'H' ? 0 : -1, first_a = s[0] == 'A' ? 0 : -1;
  for (int i = 1; i < s.size(); ++i) {
    if (s[i] != s[i - 1]) {
      roots.push_back(2 * (i + 1) - 1);
    }
    if (s[i] == 'H' && first_h == -1)
      first_h = i;
    else if (s[i] == 'A' && first_a == -1)
      first_a = i;
  }

  if (!roots.size()) {
    cout << "0\n" << (first_a == -1 ? 1 : -1) << '\n';
    return 0;
  }
  // (x - a)*(x - b) --> x*x - bx - ax + ab --> 1 + (-b - a) + ab

  vector<vector<ll>> poly(roots.size(), vector<ll>(roots.size() + 1));
  poly[0][0] = -roots[0];
  poly[0][1] = 1;

  for (int i = 1; i < roots.size(); ++i) {
    int num_prev_coefficients = i + 1;
    ll root = roots[i];
    for (int j = 0; j < num_prev_coefficients; ++j) {
      poly[i][j + 1] = poly[i - 1][j];
      poly[i][j] -= poly[i - 1][j] * root;
    }
  }

  vector<ll> &ans = poly.back();

  ll mult = 1;

  vector<pair<ll, ll>> t = {{first_a, (first_a + 1) * 2},
                            {first_h, (first_h + 1) * 2}};
  for (auto &[real_idx, x] : t) {
    ll r1 = x;
    ll val = ans[0];
    for (int i = 1; i < ans.size(); ++i) {
      val += ans[i] * r1;
      r1 *= x;
    }

    // cout << val << ' ' << s[real_idx] << '\n';
    if ((val < 0 && s[real_idx] == 'H') || (val > 0 && s[real_idx] == 'A') ||
        val == 0) {
      mult = -1;
      break;
    }
  }

  cout << roots.size() << '\n';
  for (auto it = ans.rbegin(); it != ans.rend(); ++it)
    cout << (*it) * mult << ' ';
  cout << '\n';
}

