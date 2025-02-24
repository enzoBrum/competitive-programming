#include <bits/stdc++.h>
#include <bitset>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[1001][1001];
int notes[1001];
char instruments[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;

    while (k--) {
      int num;
      cin >> num;

      instruments[i][num] = 1;
    }
  }
  
  memset(dp, 127, sizeof(dp));
  fill(begin(dp[0]), end(dp[0]), 1);
  
  for (int i = 0; i < m; ++i)
    cin >> notes[i];
  
  int prev_best = 0;
  for (int note = 1; note <= m; ++note) {
    int best = 1e9;
    for (int instrument = 0; instrument < n; ++instrument) {
      if (dp[note-1][instrument] > 1e9 && instruments[instrument][notes[note-1]])
        dp[note][instrument] = prev_best + 1;
      else if (dp[note-1][instrument] < 1e9 && instruments[instrument][notes[note-1]])
        dp[note][instrument] = dp[note-1][instrument];

      best = min(best, dp[note][instrument]);
    }
    
    prev_best = best;
  }
  
  cout << prev_best-1 << '\n';

}
