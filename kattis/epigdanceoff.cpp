#include <algorithm>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iterator>
#include <random>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <unordered_set>
#include<iostream>
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
    int n, m;
    cin >> n >> m;
    
    char grid[2000][2000];
    
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> grid[i][j];
    
    int ans = 1;
    for (int j = 0; j < m; ++j) {
        bool found = true;
        for (int i = 0; i < n; ++i) {
            if (grid[i][j] == '$') {
                found = false;
                break;
            }
        }
        
        if (found) ans++;
    }
    
    cout << ans << '\n';
}