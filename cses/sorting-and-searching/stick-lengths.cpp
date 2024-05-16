#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <random>
#include <set>
#include <vector>
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
 
typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;
 
 
int main() {
  fast_io();
  int n;
  cin >> n;
 
  vi vec;
  while (n--) {
    int temp;
    cin >> temp;
    vec.emplace_back(temp);
  }
 
  ranges::sort(vec);
  int middle = sz(vec) / 2;
 
  ull ans = 0;
  for ( auto& i : vec ) {
    ans += std::abs(vec[middle] - i);
  }
  cout << ans;
}
