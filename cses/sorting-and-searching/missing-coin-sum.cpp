#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
#define rgsort(x) { ranges::sort(x); }
 
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
    int aux;
    cin >> aux;
 
    vec.emplace_back(aux);
  }
 
  rgsort(vec);
 
  ull k = 1;
  for ( auto& n : vec ) {
    if ( n > k ) break;
 
    k += n;
  }
 
 
  cout << k << '\n';
}
