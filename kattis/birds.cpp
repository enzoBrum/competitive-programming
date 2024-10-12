#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int l, d, n;
  cin >> l >> d >> n;

  vector<int> birds(n);
  for (auto& b : birds)
    cin >> b;

  sort(all(birds));

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      int low = 6;
      ans += (birds[i] - low)/d;
    } 
    if (i == n - 1) {
      int high = l - 6;
      ans += (high - birds[i])/d;
    } 
    if (i > 0) {
      ans += (birds[i] - birds[i-1])/d;
      if (birds[i] - birds[i-1] >= d)
        ans--;
    }
  }
  
  if (!n) {
    ans = (l - 6)/d;
  } 
  
  cout << ans << '\n';
}
