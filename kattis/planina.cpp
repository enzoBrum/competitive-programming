#include <iostream>
#include <algorithm>
#include <array>
#include<vector>
#include <cmath>
#include <tuple>
#include <utility>
#include <functional>
#include <unordered_set>

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



int iteration(int num) {
  int ans = num;
  for ( int i = 1; i < num; ++i )
    ans++;
  return ans;
}

int main() {
  fast_io();

  int n;
  std::cin >> n;

  int ans = 4;
  int n_columns = 2;
  for ( int i = 0; i < n; ++i )
    {
      n_columns = iteration(n_columns);
    }
  std::cout << n_columns*n_columns;
}
