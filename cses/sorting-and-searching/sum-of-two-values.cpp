#include <algorithm>
#include <bits/ranges_algo.h>
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
 
  int n, x;
  cin >> n >> x;
 
  vi vec;
  while (n--) {
    int temp;
    cin >> temp;
    vec.emplace_back(temp);
  }
 
  vi og ( vec );
  ranges::sort(vec);
  auto bg = vec.begin();
  auto ed = vec.end() - 1;
  
  int bg_pos, ed_pos, bg_val, ed_val;
  bool success = false;
  while ( bg != ed && !success ) {
    int sum = *bg + *ed;
    if ( sum == x ) {
      success = true;
      bg_val = *bg;
      ed_val = *ed;
    }
 
    else if ( sum < x ) {
      bg++;
    }
 
    else {
      ed--;
    }
  }
 
  if (!success) cout << "IMPOSSIBLE\n";
  else {
    bg = find( og.begin(), og.end(), bg_val );
    if ( bg_val == ed_val )
      ed = find( bg+1, og.end(), ed_val );
    else 
      ed = find( og.begin(), og.end(), ed_val );
 
 
    bg_pos = bg - og.begin() + 1;
    ed_pos = ed - og.begin() + 1;
 
    
 
    cout << bg_pos << ' ' << ed_pos << '\n';
  }
}
