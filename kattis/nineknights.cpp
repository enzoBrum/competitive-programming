
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

    array<array<char, 5>,5> arr;
    vpii k;

    for (int i = 0; i < 5; ++i) {
        string buffer;
        cin >> buffer;
        for (int j = 0; j < 5; ++j) {
            char tmp = buffer[j];
            if (tmp == 'k')
                k.push_back({i,j});
            arr[i][j] = tmp;
        }
    }

    bool suc = (k.size()==9);
    for (auto&[i,j] : k) {
        if (i - 2 >= 0) {
            if (j - 1 >= 0) {
                if (arr[i-2][j-1] == 'k') {
                    suc = false;
                    break;
                }
            }
            if (j + 1 < 5) {
                if (arr[i-2][j+1] == 'k') {
                    suc = false;
                    break;
                }
            }
        }
        if (i + 2 < 5) {
            if (j - 1 >= 0) {
                if (arr[i+2][j-1] == 'k') {
                    suc = false;
                    break;
                }
            }
            if (j + 1 < 5) {
                if (arr[i+2][j+1] == 'k') {
                    suc = false;
                    break;
                }
            }
        }
        if (i - 1 >= 0) {
            if (j - 2 >= 0) {
                if (arr[i-1][j-2] == 'k') {
                    suc = false;
                    break;
                }
            }
            if (j + 2 < 5) {
                if (arr[i-1][j+2] == 'k') {
                    suc = false;
                    break;
                }
            }
        }
        if (i + 1 < 5) {
            if (j - 2 >= 0) {
                if (arr[i+1][j-2] == 'k') {
                    suc = false;
                    break;
                }
            }
            if (j + 2 < 5) {
                if (arr[i+1][j+2] == 'k') {
                    suc = false;
                    break;
                }
            }
        }
    }

    if (suc) cout << "valid";
    else cout << "invalid";           
    
}