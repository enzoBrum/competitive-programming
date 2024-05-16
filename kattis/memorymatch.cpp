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

    int n, k;
    cin >> n >> k;
    vector<string> card(n);

    int scored = 0;
    while (k--)
    {
        int c1, c2;
        string p1, p2;
        cin >> c1 >> c2 >> p1 >> p2;
        if ( p1 == p2 )
        {
            scored++;
        }

            card[c1-1] = p1;
            card[c2-1] = p2;
        
    }

    int ans = 0;
    sort(card.begin(), card.end());
    string last;

    int alone = 0, empty=0;
    for ( auto word : card )
    {
        if ( word != "" )
        {
            if ( word == last )
            {
                alone--;
                ans++;
            }
            else
                alone++;
        }
        else
            empty++;
        last = word;
    }


    if ( (empty == 2 && alone == 0 ))
        ans++;
    else if ( empty == alone )
        ans += alone;

    cout << ans - scored << '\n';

}

