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

enum DIRECTIONS {
  U,
  D,
  L,
  R
};

struct Turtle {
  int x, y;
  DIRECTIONS dir;
};


pi get_foward(Turtle& t) {
  switch ( t.dir ) {
    case U:
      return make_pair( t.x, t.y - 1 );
    case D:
      return make_pair(t.x, t.y + 1);
    case L:
      return make_pair(t.x - 1, t.y );
    case R:
      return make_pair(t.x+1, t.y);
  }
} 

void turn_left(Turtle& t) {
  switch (t.dir) {
    case U:
      t.dir = L;
      break;
    case D:
      t.dir = R;
      break;
    case L:
      t.dir = D;
      break;
    case R:
      t.dir = U;
      break;
  }
}
void turn_right(Turtle& t) {
  switch (t.dir) {
    case U:
      t.dir = R;
      break;
    case D:
      t.dir = L;
      break;
    case L:
      t.dir = U;
      break;
    case R:
      t.dir = D;
      break;
  }
}


int main() {
  fast_io();
  char board[8][8];

  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      cin >> board[i][j];
    }
  }

  string instructions;
  cin >> instructions;

  Turtle t;
  t.x = 0;
  t.y = 7;
  t.dir = R;
  
  bool bug = false;
  for (auto& c : instructions) {
    if (bug) break;
    switch ( c ) {
      case 'F': {
        auto[ x, y ] = get_foward(t);
        if ( x > 7 || y > 7 || x < 0 || y < 0 
          || board[y][x] == 'C' 
          || board[y][x] == 'I'
        ) 
          bug = true;

        t.x = x;
        t.y = y;
        break;
      }
      case 'R': {
        turn_right(t);
        break;
      }
      case 'L': {
        turn_left(t);
        break;
      }
      case 'X': {
        auto [x, y] = get_foward(t);

        if ( x>7 || y>7 || x<0 || y<0 || board[y][x] != 'I' )
            bug = true;
        else
          board[y][x] = '.';

        break;
      }
    }
  }

  if ( board[t.y][t.x] != 'D' ) bug = true;

  if (bug) cout << "Bug!\n";
  else cout << "Diamond!\n";
}
