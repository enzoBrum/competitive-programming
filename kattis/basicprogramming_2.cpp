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

void solve_1(vi& vec) {
    sort(vec.begin(), vec.end());
    auto begin = vec.begin();
    auto end = vec.end() - 1;

    bool sucess = false;
    while (begin < end && !sucess) {
        int sum = *begin + *end;
        if (sum == 7777)
            sucess = true;
        else if (sum < 7777) 
            begin++;
        else
            end--;
    }

    if (sucess) cout << "Yes";
    else cout << "No";
}

void solve_2(vi& vec) {
    sort(vec.begin(), vec.end());
    bool sucess = true;
    int last = vec[0];

    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] == last) {
            sucess = false;
            break;
        }
        last = vec[i];
    }

    if (sucess) cout << "Unique";
    else cout << "Contains duplicate";
}

void solve_3(vi& vec) {
    unordered_map<int, int> mp;
    for (auto& n : vec) {
        if (!mp.count(n)) mp[n] = 1;
        else mp[n]++;
    }

    for (auto&[k, v] : mp) {
        if (v > vec.size()/2) {
            cout << k;
            return;
        }
    }

    cout << -1;
}

void solve_4(vi& vec) {
    sort(vec.begin(), vec.end());
    if (vec.size() % 2 != 0) {
        cout << vec[vec.size()/2];
        return;
    }

    cout << vec[vec.size()/2-1] << ' ' << vec[vec.size()/2 ];
}

void solve_5(vi& vec) {
    sort(vec.begin(), vec.end());
    for (auto& n : vec) {
        if (n >= 100 && n <= 999) cout << n << ' ';
    }
}

int main() {
    int n, t;
    cin >> n >> t;

    vi vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    
    switch (t) {
        case 1:
            solve_1(vec);
            break;
        case 2:
            solve_2(vec);
            break;
        case 3:
            solve_3(vec);
            break;
        case 4:
            solve_4(vec);
            break;
        case 5:
            solve_5(vec);
            break;
    }
}