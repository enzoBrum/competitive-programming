#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include<unordered_map>
//#include<ctime>
#include<set>
#include<map>

using namespace std;
using pii = pair<int, int>;

vector<pii> directions = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  //cout.tie(0);
  
  int r, c;
  cin >> r >> c;
  
  vector<vector<int>> matrix(r, vector<int>(c));
  for (auto& row : matrix)
    for (auto& col : row)
      cin >> col;
  
   int ans = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      vector<vector<bool>> visited(r, vector<bool>(c, false));
      
      int curr_ans = 1;
      queue<pii> q;
      q.push({i, j});
      visited[i][j] = true;
      
      while (!q.empty()) {
        auto[pi, pj] = q.front();
        q.pop();
        
        for (auto&[di, dj] : directions) {
          if (pi + di < 0 || pi + di == r || pj + dj < 0 || pj + dj >= c || visited[pi+di][pj+dj] || matrix[pi][pj] > matrix[pi+di][pj+dj])
            continue;
          
          int fi = pi + di, fj = pj + dj;
          visited[fi][fj] = true;
          q.push({fi, fj});
          curr_ans++;
        }
      }
      
      ans = max(ans, curr_ans);
    }
  }
  
  cout << ans << '\n';
}

