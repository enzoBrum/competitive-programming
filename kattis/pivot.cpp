#include <bits/stdc++.h>
#include <functional>
#include <math.h>

#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vii;
using namespace std;

constexpr const int sz = 1e5 + 5;
constexpr const int k = 18;

typedef array<array<int, k>, sz> array_t;

array_t st_min, st_max;

int l(int a, int b) {return (a < b) ? a : b;}
int g(int a, int b) {return (a > b) ? a : b;}

void build_sparse( vi& vec, array_t& arr, int op ) {
    auto func = (op == 0) ? l: g;
    
    for ( int i = 0; i < vec.size(); ++i )
        arr[i][0] = vec[i];
    
    for ( int j = 1; j < k; ++j )
        for ( int i = 0; i + (1 << j)  - 1 < vec.size(); ++i )
            arr[i][j] = func( arr[i][j-1], arr[i + (1 << (j-1))][j-1] );
}

int query( array_t& arr, int L, int R, int op ) {
    auto func = (op == 0) ? l : g;
    int k = log2( R - L + 1);

    return func( arr[L][k], arr[R - (1 << k) + 1][k] );
}




int main() {
    int n;
    cin >> n;

    vi vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];
    
    build_sparse(vec, st_min, 0);
    build_sparse(vec, st_max, 1);

    int ans = 0;

    int last_query = query(st_max, 0, sz(vec) - 2, 1);
    int first_query = query(st_min, 1, sz(vec) - 1, 0);

    if ( vec[0] < first_query ) ans++;
    if ( vec.back() > last_query  ) ans++;

    for ( int i = 1; i < sz(vec) - 1; ++i ) {
        int left = query(st_max, 0, i - 1, 1);
        int right = query(st_min, i + 1, sz(vec) - 1, 0);

        if ( vec[i] > left && vec[i] < right) ans++;
    } 

    cout << ans;
}