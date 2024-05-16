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

int main() {
    while (true) {
        int r, c;
        cin >> r >> c;

        if (!r && !c) break;

        vs vec(c, "");
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char tmp; cin >> tmp;
                vec[j] += tmp;
            }
        }
        
        stable_sort(vec.begin(), vec.end(), [](const string& a, const string& b) {
            string aa, bb;
            for_each(a.begin(), a.end(), [&aa](const char& s) {aa += tolower(s);});
            for_each(b.begin(), b.end(), [&bb](const char& s) {bb += tolower(s);});

            return aa < bb;
        });
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << vec[j][i];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}