#include <algorithm>
#include <array>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <numeric>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
#define sz(x) (int(x.size()))
#define fast_io()                                                              \
  {                                                                            \
    ios::sync_with_stdio(0);                                                   \
    cin.tie(NULL);                                                             \
  }
#define rgsort(x)                                                              \
  { ranges::sort(x); }

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
  
  int num;
  while ( cin >> num ) {
    int aux = num - 1;
   
    unordered_set<int> s;
    int last;
    cin >> last;
    bool success = true;
    while (aux--) {
      int n, m;
      cin >> m;

      if (!success) continue;

      n = abs( m - last );
      if ( s.count( n ) || n > num - 1) {
        success = false;
      }
      s.insert(n);

      last = m;
    }

    // cout << "\n-------\n"<< sum << '\t' << ( num * (num-1) )/2 << '\n';
    if ( s.size() == num - 1 && success )  cout << "Jolly\n";
    else cout << "Not jolly\n";
  }
}
