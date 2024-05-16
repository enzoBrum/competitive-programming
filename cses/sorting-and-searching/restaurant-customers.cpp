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
 
enum Situation {
  B,
  L
};
 
int main() {
  int n;
  cin >> n;
  vector<pair<Situation, int>> vec;
  while (n--) {
    int x,y;
    cin >> x >> y;
    vec.emplace_back(B, x);
    vec.emplace_back(L, y);
  }
 
  sort(vec.begin(), vec.end(), [](const pair<Situation, int>& a, const pair<Situation, int>& b) {
         return a.second < b.second;
       });
 
  int ans = INT32_MIN;
  int curr = 0;
  for ( auto& p : vec ) {
    ans = max(ans, curr);
 
    if ( p.first == B ) curr++;
    else curr--;
  }
 
  cout << ans;
}
