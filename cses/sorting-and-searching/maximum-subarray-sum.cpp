#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <chrono>
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
 
  vll vec;
  while (n--) {
    ll aux;
    cin >> aux;
    vec.emplace_back(aux);
  }
 
  ll curr = 0, max = 0, ans = INT64_MIN; bool first = true;
  for ( auto& i : vec ) {
    if (first) {
      curr = i;
      max = i;
      first = false;
    }
    else {
      curr = std::max(i, curr+i);
      max += i;
    }
    
     
    max = std::max(max, exchange(curr, 0));
    ans = std::max(max, ans);
  }
 
  cout << ans;
 
}
