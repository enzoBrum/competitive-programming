#include <bits/stdc++.h>
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

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> p(n, vector<int>(m)), t(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> p[i][j];
    
    vi ans(n), time(n);

    int c = 0;
    
    for (int j = 0; j < m; ++j)  {
        ans[0] += p[0][j];
        t[0][j] += p[0][j];
    }

    for (int i = 1; i < n; ++i) {
        int delay = 0;
        for (int j = 0; j < m; ++j) {
            if (delay > t[i-1][j]) {
                delay -= t[i-1][j];
                t[i-1][j] = 0;
            } else  {
                t[i-1][j] -= delay;
                delay = 0;
            }
            
            ans[i] += t[i-1][j] + p[i][j];
            delay += p[i][j];

            t[i][j] = t[i-1][j] + p[i][j];
        }
    }

    

    for (int v : ans)
        cout << v << ' ';
    
    
}