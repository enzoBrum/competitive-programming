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
    fast_io();

    unordered_map<char, set<int>> cards = {
        {'P', set<int>()},
        {'K', set<int>()},
        {'H', set<int>()},
        {'T', set<int>()}
    };

    string s;
    cin >> s;
    bool sucess = true;
    for ( int i = 0; i < sz(s); i+=3 )
    {
        auto l = s[i];
        auto num_s = s.substr(i+1, 2);

        int num = atoi(num_s.c_str());

        if ( cards[l].find(num) != cards[l].end() )
        {
            sucess = false;
            break;
        }

        cards[l].insert(num);
    }

    if ( !sucess )
        cout << "GRESKA";
    else {
        string suits = "PKHT";

        for ( auto c : suits )
        {
            cout << 13 - cards[c].size() << ' ';
        }
    }
}

