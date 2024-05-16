#include <bits/stdc++.h>
#define sz(x) (int (x.size()))
#define fast_io() {ios::sync_with_stdio(0); cin.tie(NULL);}
#define mult_vec(name,T,n,m) std::vector<std::vector<T>>name(n, std::vector<T>(m))

typedef long long ll;
typedef unsigned long long ull;
typedef std::vector<int> vi;
typedef std::vector<ll> vll;
typedef std::vector<ull> vull;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::pair<ull, ull> pull;
typedef std::vector<pi> vpii;
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
    fast_io();

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    vvi vec(h, vi(w)), ker(n, vi(m));

    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> vec[i][j];
    
    for (int i = n-1; i >= 0; --i)
        for (int j = m-1; j >= 0; --j)
            cin >> ker[i][j];
    
    vvi ans;
    for (int i = 0; i < h - n + 1; ++i) {
        vi tmp;
        for (int j = 0; j < w - m + 1; ++j) {
            int sum = 0;
            for (int ik = 0; ik < n; ++ik) {
                for (int jk = 0; jk < m; ++jk) {
                    sum += vec[i+ik][j+jk]*ker[ik][jk];
                }
            }
            tmp.push_back(sum);
        }
        ans.emplace_back(tmp);
    }

    for (auto& v : ans) {
        for (int i = 0; i < v.size() - 1; ++i) {
            cout << v[i] << ' ';
        }

        cout << v[v.size()-1] << '\n';
    }
}