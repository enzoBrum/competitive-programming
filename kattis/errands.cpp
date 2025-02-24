#include <bits/stdc++.h>
#include <sstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

double d[101][101];
pii locs[101];
double dp[1 << 11][11];
int p[1 << 11][11];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  unordered_map<string, int> mp;
  unordered_map<int, string> mp_i_to_loc;
  mp["work"] = 0;
  mp["home"] = n-1;
  mp_i_to_loc[0] = "work";
  mp_i_to_loc[n-1] = "home";
  
  while (n--) {
    string loc;
    cin >> loc;

    double x, y;
    cin >> x >> y;

    if (loc == "work")
      locs[0] = {x, y};
    else if (loc == "home")
      locs[n-1] = {x, y};
    else {
      locs[mp.size()] = {x, y};
      mp[loc] = mp.size();
      mp_i_to_loc[mp[loc]] = loc;
    }
  }
  
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j)
      d[i][j] = d[j][i] = sqrt((locs[i].first - locs[j].first)*(locs[i].first - locs[j].first) + (locs[i].second - locs[j].second)*(locs[i].second - locs[j].second) );
  
  cin.ignore(1024, '\n');
  
  string line;
  while(getline(cin, line)) {
    stringstream ss(line);
    
    vector<int> idx_to_loc = {0};
    string location;
    while (ss >> location) {
      idx_to_loc.push_back(mp[location]);
    }
    
    memset(dp, 63, sizeof(dp));
    memset(p, -1, sizeof(p));
    
    dp[1][0] = 0;
    int n2 = idx_to_loc.size(); // work + other locations

    int limit = 1 << n2;
    for (int mask = 1; mask < limit; ++mask) {
      for (int i = 0; i < n2; ++i) {
        if (!(mask & (1 << i)))
          continue;
        
        for (int j = 0; j < n2; ++j) {
          if ((mask & (1 << j)))
            continue;

          int nmask = mask | (1 << j);
          if (dp[nmask][j] > dp[mask][i] + d[idx_to_loc[i]][idx_to_loc[j]])
            dp[nmask][j] = dp[mask][i] + d[idx_to_loc[i]][idx_to_loc[j]], p[nmask][j] = i;
        }
      }
    }
    
    double best = 1e9;
    int best_idx = -1;
    
    for (int i = 0; i < n2; ++i)
      if (dp[(1 << n2) - 1][i] + d[idx_to_loc[i]][n-1] < best)
        best = dp[(1 << n2) - 1][i] + d[idx_to_loc[i]][n-1], best_idx = i;

    vector<string> ans;
    int cur = best_idx;
    int cur_mask = (1 << n2) - 1;
    while (cur != 0) {
      ans.push_back(mp_i_to_loc[idx_to_loc[cur]]);
      int old_cur = cur;
      cur = p[cur_mask][cur];      
      cur_mask ^= (1 << old_cur);
    }
    
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
      cout << *it << ' ';
    cout << '\n';
  }
}
