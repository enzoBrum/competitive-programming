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

int main() {
  unordered_map<char, char> mp = {
  {'2', '1'}, {'3', '2'}, {'4', '3'}, {'5', '4'}, {'6', '5'}, {'7', '6'}, {'8', '7'},
  {'9', '8'}, {'0', '9'}, {'-', '0'}, {'=', '-'},
  {'W', 'Q'}, {'E', 'W'}, {'R', 'E'}, {'T', 'R'}, {'Y', 'T'}, {'U', 'Y'}, {'I', 'U'},
  {'O', 'I'}, {'P', 'O'}, {'[', 'P'}, {']', '['}, {'\\', ']'},
  {'S', 'A'}, {'D', 'S'} , {'F', 'D'}, {'G', 'F'}, {'H', 'G'}, {'J', 'H'}, {'K', 'J'},
  {'L', 'K'}, {';', 'L'}, {'\'', ';'},
  {'X', 'Z'}, {'C', 'X'}, {'V', 'C'}, {'B', 'v'}, {'N', 'B'}, {'M', 'N'}, {',', 'M'},
  {'.', ','}, {'/', '.'}, {' ', ' '}
  };

  string line;
  while(getline(cin, line)) {
    for (auto& c : line)
      c = mp[c];

    cout << line << '\n';
  }
}
