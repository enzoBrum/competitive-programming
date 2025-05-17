#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    int w, h;
    cin >> w >> h;
    
    vector<vector<char>> matrix(h, vector<char>(w));
    
    int si, sj;
    queue<pii> fire_q;
    int INF = 1e9;
    vector<vector<int>> fire(h, vector<int>(w, INF));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> matrix[i][j];
        if (matrix[i][j] == '*')
          fire_q.push({i, j}), fire[i][j] = 0;
        else if (matrix[i][j] == '@')
          si = i, sj = j;
      }
    }
    
    while (!fire_q.empty()) {
      auto[i, j] = fire_q.front();
      fire_q.pop();
      
      for (auto&[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fi >= h || fj < 0 || fj >= w)
          continue;
        if (matrix[fi][fj] == '#' || fire[fi][fj] != INF)
          continue;
        fire[fi][fj] = fire[i][j] + 1;
        fire_q.push({fi, fj});
      }
    }
    
    queue<pii> q;
    q.push({si, sj});
    vector<vector<int>> cost(h, vector<int>(w, INF));
    cost[si][sj] = 0;
    
    bool finished = false;
    while (!q.empty() && !finished) {
      auto[i, j] = q.front();
      q.pop();
      
      for (auto&[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fi >=h || fj < 0 || fj >= w) {
          cout << cost[i][j] + 1 << '\n';
          finished = true;
          break;
        }
        
        if (matrix[fi][fj] == '#' || cost[i][j] + 1 >= fire[fi][fj] || cost[fi][fj] != INF)
          continue;
        cost[fi][fj] = cost[i][j] + 1;
        q.push({fi, fj});
      }
    }
    if (!finished)
      cout << "IMPOSSIBLE\n";
  }
}
