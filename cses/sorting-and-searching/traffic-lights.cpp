#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <array>
 
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
 
int solve(set<int>& lights, multiset<int>& distances, int p) {
    auto it = lights.lower_bound(p);
    auto prev_it = prev(it);
    
    int d = *it - *prev_it;
    auto erased = distances.find(d);
    distances.erase(erased);
    distances.insert( p - *prev_it );
    distances.insert( *it - p);
    lights.insert(p);
    return  *distances.rbegin();
}
 
/*
 
0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 
0 0 0 1 0 0 1 0 0 
0 0 1 1 0 0 1 0 0
 
*/
 
 
int main() {
    int x, n;
    fast_io();
    cin >> x >> n;
 
    set<int> lights = {0, x};
    multiset<int> distances = {x};
 
    while (n--) {
        int p;
        cin >> p;
        cout << solve(lights, distances, p) << ' ';
    }
     
}
