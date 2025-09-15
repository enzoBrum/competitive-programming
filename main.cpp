#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using pli = pair<ll, int>;

int INF = 1e9;
ll INFL = 1e17;

ll d[(int) 1e5 + 1][4]; // min_d, cnt, min_flight, max_flight


signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<int> vec(n);
  for (auto& v : vec) {
    cin >> v;
    v--;
  }

  vector<pii> cycle_pos(n, {-1, -1});
  vector<vector<int>> cycles;

  for (int i = 0; i < n; ++i) {
    if (cycle_pos[i].first != -1)
      continue;

    vector<int> cur_cycle;

    int cur = i;
    // cout << "I:" << i << "= ";
    int cidx = cycles.size();
    int cnt = 0;
    while (cycle_pos[cur].first == -1) {
      cycle_pos[cur].first = cidx;
      cycle_pos[cur].second = cnt;
      cur_cycle.push_back(cur);
      cnt++;
      // cout << cur << ' ';
      cur = vec[cur];
    }
    // cout << endl;

    cycles.push_back(std::move(cur_cycle));
  }

  while (q--) {
    int u, k;
    cin >> u >> k;

    u--;
    auto[cidx, cpos] = cycle_pos[u];

    if (cpos + k >= cycles[cidx].size() && vec[cycles[cidx].back()] == cycles[cidx].back()) {
      cout << cycles[cidx].back()+1 << '\n';
      continue;
    }
    
    while (cpos + k >= cycles[cidx].size() && cidx != cycle_pos[vec[cycles[cidx].back()]].first) {      
      k -= (cycles[cidx].size() - cpos);
      int og_cidx = cidx;
      cidx = cycle_pos[vec[cycles[cidx].back()]].first;
      cpos = cycle_pos[vec[cycles[og_cidx].back()]].second;
    }

    int cbegin = cycle_pos[vec[cycles[cidx].back()]].second;
    int csize = cycles[cidx].size() - cbegin;

    if (cpos + k < cycles[cidx].size()) {
      cout << cycles[cidx][cpos+k]+1 << '\n';
      continue;
    }

    if (cbegin > cpos) {
      k -= (cbegin - cpos);
      cpos = 0;
    } else {
      cpos -= cbegin;
    }
    

    k %= csize;

    int v = cpos + k < csize ? cpos + k : cpos + k - csize;
    cout << cycles[cidx][v+cbegin]+1 << '\n';
  }
}
