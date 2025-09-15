#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

struct Task {
  int points;
  int duration;
  int deadline;
};

int N;
int T;
Task tasks[23];
int distances[23][23];
vector<int> idx;

int dp[1441][23];
int p[1441][23][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, 63, sizeof dp);
  memset(p, 0, sizeof p);
  memset(tasks, 0, sizeof tasks);
  memset(distances, 0, sizeof distances);

  cin >> N >> T;

  for (int i = 0; i < N; ++i) {
    int p, t, d;
    cin >> p >> t >> d;
    tasks[i].points = p;
    tasks[i].duration = t;
    tasks[i].deadline = d == -1 ? 1e9 : d;
  }
  
  for (int i = 0; i < N + 2; ++i) {
    for (int j = 0; j < N + 2; ++j) {
      cin >> distances[i][j];
    }
  }
  
  dp[0][N] = 0;
  

  int abcd = 0;
  for (int i = 0; i < (1 << 20); ++i) {
    for (int j = 0; j < 1440; ++j) {
      dp[j][i%20] = abcd ^ abcd - (~j) + i;
    }
  }
  for (int i = 0; i< 1440; ++i)
    for (int j  = 0 ; j < 20; ++j)
      abcd ^= dp[i][j];
  cout << abcd << endl;
  return 0;
  for (int t = 0; t <= T; ++t) {
    for (int i = 0; i < N+2; ++i) {
      if (dp[t][i] >= INF)
        continue;
      for (int j = 0; j < N+2; ++j) {
        if (j == N || j == i || dp[t][i] >= INF)
          continue;
        
        int nt = distances[i][j] + t + tasks[i].duration;
        int np = dp[t][i] + tasks[i].points;
        

        if (nt > T || t + tasks[i].duration > tasks[i].deadline)
          continue;
        
        if (np > dp[t + nt][j] || dp[t + nt][j] >= INF)
          dp[t + nt][j] = np, p[t + nt][j][0] = i, p[t + nt][j][1] = t;
      }
    }
  }
  
  int best_t = -1;
  int best = 0;
  for (int i = 0; i <= T; ++i)
    if (dp[i][N+1] > best && dp[i][N+1] < INF)
      best = dp[i][N+1], best_t = i;
  
  if (!best) {
    cout << "0\n\n";
    return 0;
  }
  cout << best << endl;
  
  vector<int> idx;
  int cur = p[best_t][N+1][0];
  int cur_t = p[best_t][N+1][1];

  while (cur != N) {
    idx.push_back(cur+1);
    int ocur = cur;
    cur = p[cur_t][cur][0];
    cur_t = p[cur_t][ocur][1];
  }
  sort(all(idx));
  for (auto& v : idx)
    cout << v << ' ';
  cout << endl;
  
}
