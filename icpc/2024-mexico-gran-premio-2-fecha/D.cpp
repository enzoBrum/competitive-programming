#include <bits/stdc++.h>
#include <string>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

/**
 * C_n_k = n!/k!(n-k)!
 * k=2
 *
 * C_n_2 = n!/2*(n-2)!
 * C_n_2 = n*(n-1)/2
 */

vector<int> precalculate(int limit) {
  vector<vector<pair<int, unordered_set<int>>>> dp(
      801, vector<pair<int, unordered_set<int>>>(10));

  for (int i = 10; i < 100; ++i) {
    for (int j = i + 1; j < 100; ++j) {
      int si = 0, sj = 0;
      string ssi = to_string(i), ssj = to_string(j);

      if (i < 10)
        ssi = "0" + ssi;
      if (j < 10)
        ssj = "0" + ssj;

      bool found = true;
      for (int k = 0; k < ssi.size() && found; ++k) {
        if (ssi[k] == ssj[k])
          found = false;
        else
          si += (ssi[k] - '0'), sj += (ssj[k] - '0');
      }

      if (!found || si != sj)
        continue;

      dp[2][ssi[0] - '0'].first++;
      dp[2][ssi[0] - '0'].second.insert(si);
      dp[2][ssj[0] - '0'].first++;
      dp[2][ssj[0] - '0'].second.insert(sj);
    }
  }
  dp[2][0].first = 10;
  for (int i = 0; i < 10; ++i)
    dp[2][0].second.insert(i);

  for (int i = 3; i <= limit; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        for (int l = k + 1; l < 10; ++l) {
        }
      }
    }
  }

  return {};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  precalculate(3);
}
