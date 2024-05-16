#include<cmath>
#include <sstream>
#include<cstdint>
#include<iterator>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<functional>
 
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
#define mult_vec(name,T,n,m) std::vector<std::vector<T>>name(n, std::vector<T>(m))
// #define DB 

#ifdef DB
  #define DEBUG(s) std::cout << s << '\n';
#else
  #define DEBUG(s);
#endif
 
typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<char> vc;
typedef std::vector<std::vector<char>> vvc;
typedef std::vector<std::vector<std::string>> vvs;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vpi;
typedef std::vector<pll> vpll;
typedef std::vector<pull> vpull;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<ll>> vvll;
typedef std::vector<std::vector<ull>> vvull;
typedef std::vector<std::vector<pi>> vvpii;
typedef std::vector<std::vector<pll>> vvpll;
typedef std::vector<std::vector<pull>> vvpull;
 
using namespace std;

int count_steps(vi& vec) {
    vi sorted_vec;
    sorted_vec.push_back(vec[0]);

    int steps = 0;
    for (int i = 1; i < vec.size(); ++i) {
        int pos = sorted_vec.size();
        for (int j = sorted_vec.size()-1; j >= 0; --j) {
            if (sorted_vec[j] > vec[i]) {
                steps++;
                pos = j;
            }
        }

        if (pos == sorted_vec.size()) sorted_vec.push_back(vec[i]);
        else sorted_vec.insert(sorted_vec.begin() + pos, vec[i]);
    }
    return steps; 
}  

int main() {
    int t; cin >> t;
    vi vec(20);
    while (t--) {
        int k; cin >> k;
        for (int i = 0; i < 20; ++i)
            cin >> vec[i];

        int steps = count_steps(vec);
        cout << k << ' ' << steps << '\n';
    }
}