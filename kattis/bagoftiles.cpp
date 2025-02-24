#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

/*
i -> sum
j -> first j coins
k -> with x coins

O(N^3)

for k in (0..n-1)
  dp[i][j][k] += max(
    dp[i][j-1][k],
    dp[i - c][j-1][k-1]
  )

O(N * 2 ** (N/2)) meet in the middle

*/

int dp[2][10'000 * 30 + 2];

void gen_subsets(vector<int> &labels, int begin, int end, int n) {
  int limit = 1 << (end - begin);

  for (int mask = 0; mask < limit; ++mask) {
    int cur_sum = 0;
    for (int j = 0; j < end - begin; ++j)
      if ((mask & (1 << j)))
        cur_sum += labels[begin + j];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int game;
  cin >> game;

  for (int g = 1; g <= game; ++g) {
    int m;
    cin >> m;

    vector<int> labels(m);
    for (auto &l : labels)
      cin >> l;

    int n, t;
    cin >> n >> t;

    int sum = accumulate(all(labels), 0);
    memset(dp, 0, sizeof(dp));
    memset(memo, 0, sizeof(memo));

    int mid = labels.size() / 2;
  }
}
