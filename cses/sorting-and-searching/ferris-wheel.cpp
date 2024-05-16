#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
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
 
  int n,x;
  cin >> n >> x;
 
  multiset<int> w;
  while (n--) {
    int aux;
    cin >> aux;
    w.insert(aux);
  }
 
  int ans = 0;
  auto it = w.begin();
  
  auto last_to_end = prev(w.end(), 1);
  while ( it != w.end() ) {
    if ( it == last_to_end ) {
      ans++;
      it = w.erase(it);
 
      continue;
    }
 
    else if ( *it + *last_to_end <= x ) {
      ans++;
 
      auto aux = last_to_end;
      last_to_end--;
 
      w.erase(aux);
      it = w.erase(it);
      continue;
    }
 
    
    auto ti = w.lower_bound(x-*it);
    if ( ti == it ) ti++;
 
    auto prev_ti = prev(ti, 1);
 
    if ( ti == w.end() ) {
      ans++;
    }
    
    else if ( *it + *ti <= x ) {
      ans++;
      w.erase(ti);
    }
    else if ( it != prev_ti && *it + *prev_ti <= x ) {
      ans++;
      w.erase(prev_ti);
    }
    else {
      ans++;
    }
 
    it = w.erase(it);
  }
 
  cout << ans;
 
}
