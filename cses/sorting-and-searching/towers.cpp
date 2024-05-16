#include <algorithm>
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
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
    fast_io();
 
    int n;
    cin >> n;
 
    multiset<int> st;
    while (n--) {
        int t; cin >> t;
 
        auto it = st.upper_bound(t);
        if (it == st.end()) {
            st.insert(t);
            continue;
        }
 
        auto nh = st.extract(it);
        nh.value() = t;
        st.insert(std::move(nh));
 
    }
 
    cout << sz(st) <<  '\n';
}
