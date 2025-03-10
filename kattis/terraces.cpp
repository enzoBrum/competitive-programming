#include <algorithm>
#include <bits/stdc++.h>
#include <map>

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

int matrix[501][501];
int matrix_min_h[501][501];
int cc_size[501][501];
char matrix_visited[501][501];
int N, M;

stack<pii> st;


void dfs(int i, int j, int ph) {
  //cout << "(" << i << ", " << j << ")=" << matrix[i][j] << endl;
  matrix_visited[i][j] = 1;
  st.push({i, j});
  
  int min_h = matrix[i][j];
  for (auto&[di, dj] : directions) {
    int fi = i + di, fj = j + dj;

    if (fi < 0 || fj < 0 || fi >= N || fj >= M)
      continue;
    min_h = min(min_h, matrix[fi][fj]);
    min_h = min(min_h, matrix_min_h[fi][fj]);
    if (matrix_visited[fi][fj])
      continue;
    if (matrix[i][j] < matrix[fi][fj])
      continue;
    
    dfs(fi, fj, matrix[i][j]);
  }
  
  matrix_min_h[i][j] = min_h;
  cc_size[i][j] = 1;
  if (ph == matrix[i][j])
    return;
  
  
  //cout << "FINISH (" << i << ", " << j << ")=" << matrix[i][j] << endl;
  int sz = 1;
  stack<pii> cur_cc;
  while (st.top() != (pii){i, j} && matrix[st.top().first][st.top().second] == matrix[i][j]) {
    sz++;
    cur_cc.push(st.top());
    min_h = min(min_h, matrix_min_h[st.top().first][st.top().second]);
    st.pop();
    
    //cout << "INCLUDE (" << cur_cc.top().first << ", " << cur_cc.top().second << ")=" << matrix[cur_cc.top().first][cur_cc.top().second] << endl;

  }
  
  cur_cc.push({i, j});
  while (!cur_cc.empty()) {
    auto[ci, cj] = cur_cc.top();
    cur_cc.pop();

    matrix_min_h[ci][cj] = min_h;
    cc_size[ci][cj] = sz;
  }
  st.pop();
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(matrix_visited, 0, sizeof matrix_visited);
  memset(matrix_min_h, 127, sizeof matrix_min_h);
  
  cin >> M >> N;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      cin >> matrix[i][j];
  
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (!matrix_visited[i][j])
        dfs(i, j, -1);
  
  //for (int i = 0; i < N; ++i) {
  //  for (int j = 0; j < M; ++j)
  //    cout << matrix[i][j] << '/' <<  matrix_min_h[i][j] << '/' << cc_size[i][j] << ' ';
  //  cout << endl;
  //}
  
  int ans = 0;
  memset(matrix_visited, 0, sizeof matrix_visited);
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (matrix_visited[i][j] || matrix[i][j] != matrix_min_h[i][j])
        continue;
      queue<pii> q;
      q.push({i, j});

      matrix_visited[i][j] = true;
      while (!q.empty()) {
        auto[ci, cj] = q.front();
        q.pop();

        for (auto&[di, dj] : directions) {
          int fi = ci + di, fj = cj + dj;

          if (fi < 0 || fj < 0 || fi >= N || fj >= M || matrix_visited[fi][fj] || matrix[fi][fj] != matrix[i][j])
            continue;
          matrix_visited[fi][fj] = true;
          q.push({fi, fj});
        }
      }
      
      ans += cc_size[i][j];
    }
  }
  
  cout << ans << '\n';
}
