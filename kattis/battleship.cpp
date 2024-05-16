#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <random>
#include <set>
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


enum ROUND {
  A, B
};

vii get_ships(int h) {
  vii ret;
  for ( int y = h-1; y >= 0; --y ) {
    string line;
    cin >> line;
    
    size_t ship_i = 0, bg_i = 0;
    while (true) {
      ship_i = line.find('#', bg_i);
      bg_i = ship_i + 1;

      if ( ship_i == string::npos ) break;
      ret.emplace_back(ship_i, y);
    }
  }

  return ret;
}



int main() {
  int t;
  cin >> t;

  while (t--) {
    int w,h,n;
    cin >> w >> h >> n;

    vii va = get_ships(h);
    vii vb = get_ships(h);

    bool last_round = false, end_game = false;
    ROUND r = A;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      if (end_game) continue;

      auto& enemy = ( r == A ) ? vb : va;
      auto& ally = ( r == A ) ? va : vb;

      auto it = find_if( enemy.begin(), enemy.end(), [&x, &y](const pi& p) {
                          return p.first == x && p.second == y;
      });

      if ( it == enemy.end() ) {
        if (r == B && !sz(ally) ) end_game = true;
        r = (r == A) ? B : A;
        
        continue;
      }

      enemy.erase(it);
      if ( !sz(enemy) ) {
        if (r == B) end_game = true;

        last_round = true;
        r = (r == A) ? B : A;
        continue;
      }
      

    }


    if (( !sz(va) && !sz(vb)) || (sz(va) && sz(vb)))
      cout << "draw\n";
    else if (!sz(va))
      cout << "player two wins\n";
    else 
      cout << "player one wins\n";
  }
}
