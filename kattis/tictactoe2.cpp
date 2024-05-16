#include <algorithm>
#include <array>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <random>
#include <set>
#include <string>
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

// XOX
// OXO
// XOX
//
// OXO
// XXO
// XOX
//
// OXO
// XXO
// X.O

bool get_winners(array<array<char, 3>, 3> &grid, char character) {
    if (grid[0][0] == character && grid[0][1] == character && grid[0][2] == character)
        return true;
    
    if (grid[1][0] == character && grid[1][1] == character && grid[1][2] == character)
        return true;
        
    if (grid[2][0] == character && grid[2][1] == character && grid[2][2] == character)
        return true;
        
    if (grid[0][0] == character && grid[1][0] == character && grid[2][0] == character)
        return true;
    
    if (grid[0][1] == character && grid[1][1] == character && grid[2][1] == character)
        return true;
        
    if (grid[0][2] == character && grid[1][2] == character && grid[2][2] == character)
        return true;
        
    if (grid[0][0] == character && grid[1][1] == character && grid[2][2] == character)
        return true;
        
    if (grid[0][2] == character && grid[1][1] == character && grid[2][0] == character)
        return true;
    
    return false;
}

int main() {
  fast_io();

  int t;
  cin >> t;
  while (t--) {
    int x = 0, o = 0;
    array<array<char, 3>, 3> board;
    for (int i = 0; i < 3; ++i) {
      string s;
      cin >> s;

      for (int j = 0; j < 3; ++j) {
        board[i][j] = s[j];

        if (s[j] == 'X')
          x++;
        else if (s[j] == 'O')
          o++;
      }
    }

    bool success = true;
    bool ow = get_winners(board, 'O');
    bool xw = get_winners(board, 'X');
    if (o > x || x-o > 1)
      success = false;
    else if (ow && xw )
      success = false;
    else if (xw && x == o)
      success = false;
    else if (ow && x != o)
      success = false;
    //else if ( !xw && !ow && ( x+o != 9 || x - o != 1 )  )
      //success = false;

    // cout << n_winners << '\t' << c_winner << '\n';
    string ans = success ? "yes" : "no";
    cout << ans << '\n';
  }
}
