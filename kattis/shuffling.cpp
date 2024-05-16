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

    int n;
    string w;
    cin >> n >> w;

    vi vec(n);
    iota(vec.begin(), vec.end(), 1);

    int left, right;
    int middle = ( n&1 && w == "out" ) ? n/2+1 : n/2;
    if ( w == "out" )
    {
        left = 0;
        right = middle;
    }    
    else {
        left = middle;
        right = 0;
    }
    
    int ans = 0;
    vi aux = vec;
    vi tmp = aux;
    bool out = w == "out";
    do
    {
        aux = tmp;
        int l = left, r = right;
        int i = 0;
        while (( ( out && l != right && r != n ) || ( !out && l != n && r != left ) ) && i != n)
        {
            tmp[i] = aux[l];
            ++i;
            
            if ( i < n )
                {
                    tmp[i] = aux[r];
                    ++i;
                }
            ++l;++r;
            
        }
        ++ans;

        if ( ((l != right && out) || ( l != n && !out )) && i < n )
            tmp[i] = aux[l];
        else if ( ( (r != n && out) || (r != left && !out) ) && i < n )
            tmp[i] = aux[r];

    } while ( tmp != vec );
    
    
 
    cout << ans << '\n';
}

