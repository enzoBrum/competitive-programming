#include<queue>
#include<cmath>
#include<sstream>
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
typedef std::vector<bool> vb;
typedef std::vector<std::vector<bool>> vvb;
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

int main() {
    fast_io();
    int n, m;
    cin >> n >> m;

    vvc vec(n, vc(m));
    vvi ans(n, vi(m,0));
    vvb visited(n+2, vb(m+2, false));
    
    for (int j = 0; j < visited[0].size(); ++j)
        visited[0][j] = visited[visited.size()-1][j] = true;
    for (int i = 0; i < visited.size(); ++i)
        visited[i][0] = visited[i][visited[0].size()-1] = true;

    queue<pi> q1, q2;
    auto* curr = &q1;
    auto* next = &q2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char tmp;
            cin >> tmp;

            vec[i][j] = tmp;
            if (tmp == 'T') curr->emplace(i,j);
            else visited[i+1][j+1] = true;
        }
    }

    queue<pi> q;
    int num_rings = 1;
    while (!curr->empty() || !next->empty()) {
        if (curr->empty()) {
            num_rings++;
            swap(curr, next);
            while (!q.empty()) {
                pi p = q.front();
                q.pop();
                visited[p.first+1][p.second+1] = true;
            }
            continue;
        }

        pi pos = curr->front();
        curr->pop();
        ans[pos.first][pos.second]++;
        if (
            visited[pos.first+1+1][pos.second+1] ||
            visited[pos.first+1-1][pos.second+1] ||
            visited[pos.first+1][pos.second+1+1] ||
            visited[pos.first+1][pos.second+1-1]
        ) 
            q.push(pos);
        else
            next->push(pos);
    }


    for (auto& v : ans) {
        for (auto& n : v) {
            if (num_rings >= 10) cout << '.';

            if (!n) cout << "..";
            else if (n < 10) cout << '.' << n;
            else cout << n;
        }
        cout << '\n';
    }   
}