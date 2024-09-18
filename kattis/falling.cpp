#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll d;
  cin >> d;

  // a^2 - b^2 = d
  // -b^2 = d - a^2
  // b^2 = a^2 - d
  // b = sqrt(a^2 - d)
  for (ll i = 0; i <= d; ++i) {
    ll tmp = i * i - d;
    ll tmpsqrt = sqrt(tmp);
    if (tmpsqrt * tmpsqrt == tmp && tmp >= 0) {
      tmp = sqrt(tmp);
      if (tmp < i)
        swap(i, tmp);
      cout << i << ' ' << tmp << endl;
      return 0;
    }
  }
  cout << "impossible\n";
}
