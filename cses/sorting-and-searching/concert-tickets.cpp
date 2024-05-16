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
  int n, m;
  cin >> n >> m;
 
  multiset<int> vn;
  while(n--) {
    int a;
    cin >> a;
    vn.insert(a);
  }
  
 
  auto bend = prev(vn.end(),1);
 
  while ( m-- ) {
    int num;
    cin >> num;
 
    if ( !vn.size() ) {
      cout << "-1\n";
      continue;
    }
 
    if ( num >= *bend ) {
      cout << *bend << '\n';
 
      auto aux = bend;
      
      if (bend != vn.begin())
        bend--;
 
      vn.erase(aux);
      continue;
    }
 
    auto it = vn.lower_bound(num);
    auto prev_it = it;
    if ( prev_it != vn.begin() ) prev_it--;
 
    if ( *it <= num ) {
      cout << *it << '\n';
      vn.erase(it);
    }
 
    else if ( *prev_it <= num ) {
      cout << *prev_it <<  '\n';
      vn.erase(prev_it);
    }
    else {
      cout << "-1\n";
    }
  }
}
