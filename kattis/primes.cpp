#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<int> primes, ans;
ull x, y;

void backtrack(int k, ull cur) {
  if (k == primes.size())
    return;
  
  while (cur <= y) {
    if (cur >= x)
      ans.push_back(cur);  
    for (int i = k+1; i < primes.size(); ++i)
      if (cur * primes[i] <= y)
        backtrack(i, cur * primes[i]);
    cur *= primes[k];
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  while (cin >> n && n) {
    primes.assign(n, 0);
    ans.clear();
    for (auto& p : primes)
      cin >> p;

    cin >> x >> y;    
    backtrack(0, 1);
    
    sort(ans.begin(), ans.end());
    if (!ans.size())
      cout << "none\n";
    else
      for (int i = 0; i < ans.size(); ++i)
        if (!i || ans[i] != ans[i-1])
        cout << ans[i] << (i == ans.size() - 1 ? '\n' : ',');
  }
}
