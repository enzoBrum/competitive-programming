#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  unordered_map<int, int> mp;
  int n;
  cin >> n;

  while (n--) {
    int num;
    cin >> num;

    mp[num]++;
  }

  int greatest_freq = 0;
  for (auto &[k, v] : mp)
    greatest_freq = max(greatest_freq, v);

  int ans = -1e9;
  for (auto &[k, v] : mp)
    if (v == greatest_freq)
      ans = max(ans, k);
  cout << ans << '\n';
}
