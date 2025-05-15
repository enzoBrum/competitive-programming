#include <bits/stdc++.h>
#include <cstdlib>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool dp[(int)2e5 + 10], nxt[(int)2e5 + 10];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int bst = -1;
  map<int, int> mp;
  int limit = 0;
  for (int i = 0; i < n; ++i) {
    int g, r;
    cin >> g >> r;

    if (mp.count(g))
      mp[g] += 1;
    else
      mp[g] = 1;

    limit += g;
    if (i)
      bst = gcd(bst, r);
    else
      bst = r;
  }

  memset(dp, 0, sizeof dp);

  dp[limit] = 1;
  dp[0] = 1;
  vector<pii> vec;
  for (auto &[k, v] : mp)
    vec.emplace_back(k, v);

  for (auto [num, cnt] : vec) {
    queue<pii> q;
    for (int sum = limit; sum >= 0; --sum) {
      if (sum == num && !dp[sum]) {
        nxt[num] = 1;
        q.push({cnt, num});
        continue;
      }
      if (!dp[sum])
        continue;

      if (sum - num >= 0)
        nxt[sum - num] = 1, q.push({cnt, sum - num});
    }
    cnt--;
    while (!q.empty() && cnt) {
      while (!q.empty() && q.front().first > cnt) {
        auto v = q.front().second;
        if (v - num >= 0 && !dp[v - num] && !nxt[v - num])
          nxt[v - num] = 1, q.push({cnt, v - num});
        q.pop();
      }
      cnt--;
    }
    memcpy(dp, nxt, sizeof nxt);
  }

  // cout << bst << endl;
  // cout << limit << endl;
  for (int i = 1; i < limit; ++i) {
    if (!dp[i])
      continue;
    // cout << i << " -> " << dp[i] << endl;
    if (abs(i - (abs(i - limit))) % bst == 0) {
      // cout << "abs(" << i << " - " << limit << ")=" << abs(i - limit) << " -
      // "
      //      << i << " = " << abs(i - (abs(i - limit))) << endl;
      // cout << i << ' ' << limit << endl;
      cout << "Y\n";
      return 0;
    }
  }

  cout << (vec[0].first == 0 && limit % bst == 0 ? "Y\n" : "N\n");
}
