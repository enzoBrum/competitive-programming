#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

ll solve(int n, int k, vector<pii>& vec, vector<int>& pref) {
  ll ans = 0;
  int cur_t = k;
  int cur_d = 0;
  
  int i = 0;
  
  while (i < n) {
    cout << "\n========CURRENT: " << vec[i].first << ", " << vec[i].second << '\n';
    //cout << "cur_t: " << cur_t << ", cur_d: " << cur_d << ", ans: " << ans << ", i: " << i << "\n=======\n";
    if (vec[i].second == cur_t) {
      ans += 2*vec[i].first - cur_d;
      cur_d = 0;
      cur_t = k;
      i++;
      cout << "A\n";
      continue;
    }
    
    if (vec[i].second > cur_t && cur_t) {
      
      if (!(cur_t < pref[n] - pref[i] && k >= pref[n] - pref[i]))
        ans += 2*vec[i].first - cur_d, vec[i].second -= cur_t, cout << "B\n";
      else
        ans += cur_d, cout << "C\n";
      
      cur_d = 0;
      cur_t = k;
      continue;
    }
    
	if (cur_t < pref[n] - pref[i] && k >= pref[n] - pref[i]) 
      ans += cur_d, cur_d = 0, cur_t = k, cout << "D\n";
    else
      ans += vec[i].first - cur_d, cur_d = vec[i].first, cur_t -= vec[i].second, i++, cout << "E\n";
  }
  
  cout << "ANS: " << ans+cur_d << '\n';
  return ans + cur_d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;
  vector<pii> va, vb;
  for (int i = 0; i < n; ++i) {
    int num, t;
    cin >> num >> t;
    if (num < 0)
      va.push_back({-num, t});
    else
		      vb.push_back({num, t});
  }
  
  sort(all(va));
  sort(all(vb));
  
  vector<int> ta(va.size() + 1), tb(vb.size() + 1);
  
  ta[0] = tb[0] = 0;
    
  for (int i = 1; i <= va.size(); ++i)
    ta[i] = ta[i-1] + va[i-1].second;
  for (int i = 1; i <= vb.size(); ++i)
    tb[i] = tb[i-1] + vb[i-1].second;
    
  cout << solve(va.size(), k, va, ta) + 
  solve(vb.size(), k, vb, tb) << '\n';
  
}