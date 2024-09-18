#include <vector>
#include <numeric>
#include<utility>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
#include<functional>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<stack>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
using ull = unsigned  long long;

int cnt = 0;
int n;
vector<int> colors;
vector<char> used;
vector<vector<int>> constraint;
vector<int> best, cur;

void backtrack(int i, int last) {
  if (i == n) {
    cnt++;
    if (best.empty()) {
      best = cur;
      return;
    }
    if (best > cur)
      best = cur;
    return;
  }
  
  for (int j = 0; j < n; ++j) {
    if (used[j])
      continue;
    if (find(constraint[j].begin(), constraint[j].end(), last) != constraint[j].end())
      continue;
    used[j] = true;
    cur.push_back(j);
    backtrack(i+1, j);
    cur.pop_back();
    used[j] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    colors.clear();
    used.assign(n, false);
    best.clear();
    cur.clear();
    constraint.assign(n, {});
    cnt = 0;
    
    unordered_map<string, int> msi;
    unordered_map<int, string> mis;
    
    for (int i = 0; i < n; ++i) {
      string cur;
      cin >> cur;
      msi[cur] = msi.size();
      mis[msi.size() - 1] = cur;
      colors.push_back(msi.size() - 1);
    }
    
    int m;
    cin >> m;
    
    while (m--) {
      string a, b;
      cin >> a >> b;
      
      constraint[msi[a]].push_back(msi[b]);
      constraint[msi[b]].push_back(msi[a]);
    }
    
    backtrack(0, -1);
    
    cout << cnt << '\n';
    for (auto& c : best)
      cout << mis[c] << ' ';
    cout << '\n';
  }
}
