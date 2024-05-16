#include <iostream>
#include <algorithm>
#include <array>
#include<vector>
#include <cmath>
#include <tuple>
#include <utility>
#include <functional>
#include <unordered_set>
#include <iomanip>

#define fast_io() std::ios::sync_with_stdio(0); std::cin.tie(0)
#define sz(x) (int (x.size()))

typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;



int main() {
  fast_io();
  double ans = 0;

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i)
    {
      double q, y;
       std::cin >> q >> y;
      ans += (q*y);
    }
  std::cout << std::fixed << std::setprecision(3) << ans;
}

