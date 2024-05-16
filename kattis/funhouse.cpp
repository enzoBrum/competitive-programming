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


char change_direction(char mirror, char& d) {
    if (mirror == '/') {
        if (d == 'u') return 'r';
        else if (d == 'd') return 'l';
        else if (d == 'r') return 'u';
        return 'd';
    }

    /* \ */
    if (d == 'u') return 'l';
    else if (d == 'd') return 'r';
    else if (d == 'l') return 'u';
    return 'd';
}

char d_left(pi& p, vvc& vec) {
    p.second--;
    return vec[p.first][p.second];
}

char d_right(pi& p, vvc& vec) {
    p.second++;
    return vec[p.first][p.second];
}

char d_up(pi& p, vvc& vec) {
    p.first--;
    return vec[p.first][p.second];
}

char d_down(pi& p, vvc& vec) {
    p.first++;
    return vec[p.first][p.second];
}

unordered_map<char, function<char(pi&, vvc&)>> mp = {
    {'u', d_up}, {'d', d_down}, {'l', d_left}, {'r', d_right}
};

int main() {
    fast_io();
    int r = 0;
    while (true) {
        ++r;
        int w, l;
        cin >> w >> l;

        if (!w && !l) break;

        vector<vector<char>> vec(l, vector<char>(w));
        pi pos = {0,0};

        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < w; ++j) {
                char c; cin >> c;
                vec[i][j] = c;
                if (c == '*') pos = {i,j};
            }
        }


        char d = '\0';
        if (pos.first == 0) d = 'd';
        else if (pos.first == l-1) d = 'u';
        else if (pos.second == 0) d = 'r';
        else d = 'l';


        while (vec[pos.first][pos.second] != 'x') {
            while (mp[d](pos, vec) == '.');
            char curr = vec[pos.first][pos.second];
            if (curr == 'x') break;
            DEBUG(curr);
            d = change_direction(curr, d);
        }

        vec[pos.first][pos.second] = '&';
        cout << "HOUSE " << r << '\n';
        for (auto& v : vec) {
            for (auto& c : v)
                cout << c;
            cout << '\n';
        }
    }
}

