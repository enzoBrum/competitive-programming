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

  int n;
  cin >> n;

  vector<int> vec(n);
  for (auto& v : vec)
    cin >> v;
  sort(rall(vec));
  
  ll ans = 0;
  for (int i = 2; i < n; i += 3)
    ans += vec[i];
  cout << ans << '\n';

}

