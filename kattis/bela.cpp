#include <bits/stdc++.h>
#define fast_io() std::ios::sync_with_stdio(0); std::cin.tie(0)
#define sz(x) (int (x.size()))

typedef long long ll;
typedef uint64_t ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
using namespace std;



int main() {
    unordered_map<char, pi> map {
        { 'A', make_pair(11, 11) },
        { 'K', make_pair(4, 4) },
        { 'Q', make_pair(3, 3) },
        { 'J', make_pair(20, 2) },
        { 'T', make_pair(10, 10) },
        { '9', make_pair(14, 0) },
        { '8', make_pair(0, 0) },
        { '7', make_pair(0, 0) }
    };

    int n;
    char dom;
    cin >> n >> dom;

    n = n*4;
    int ans = 0;
    while (n--) {
        char val;
        char suit;
        cin >> val >> suit;

        if ( suit == dom )
            ans += map[val].first;
        else
            ans += map[val].second;
    }
    cout << ans << '\n';
}

