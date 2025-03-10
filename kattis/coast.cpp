#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<vector<char>> matrix;
vector<vector<char>> visited;
vector<vector<char>> is_lake;

int N, M;

vector<pii> directions = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

inline bool inside(int i, int j) {
  return !(i < 0 || j < 0 || i >= N || j >= M);
}

void find_lakes(int i, int j, bool cur) {

  queue<pii> q;
  stack<pii> st;
  q.push({i, j});
  
  visited[i][j] = true;
  while (!q.empty()) {
    auto[i, j] = q.front();
    q.pop();

    for (auto&[di, dj] : directions) {
      int fi = i + di, fj = j + dj;
      if (!inside(fi, fj)) {
        cur = false;
        break;
      }
    }

    for (auto&[di, dj] : directions) {
      int fi = i + di, fj = j + dj;
      if (!inside(fi, fj) || matrix[fi][fj] != '0' || visited[fi][fj])
        continue;
    visited[fi][fj] = true;
      q.push({fi, fj});
    }
    
    st.push({i, j});
  }
  
  if (!cur)
    return;
  while (!st.empty()) {
    auto[i, j] = st.top();
    st.pop();
    is_lake[i][j] = true;
  }
}

int dfs(int i, int j) {
  
  
  stack<pii> st;
  st.push({i, j});
  
  int ans = 0;
  visited[i][j] = true;
  while (!st.empty()) {
    auto[i, j] = st.top();
    st.pop();
    visited[i][j] = true;
    for (auto&[di, dj] : directions) {
      int fi = i + di, fj = j + dj;
      if (!inside(fi, fj) || (matrix[fi][fj] == '0' && !is_lake[fi][fj]))
        ans++;
      else if (!visited[fi][fj] && matrix[fi][fj] == '1')
        st.push({fi, fj}), visited[fi][fj] = true;
    }
  }
  return ans;
}



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  matrix.assign(N, vector<char>(M));
  visited.assign(N, vector<char>(M, 0));
  is_lake.assign(N, vector<char>(M, 0));
  
  for (auto& row : matrix)
    for (auto& cell : row)
      cin >> cell;

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (matrix[i][j] == '0' && !visited[i][j])
        find_lakes(i, j, true);
  int ans = 0;
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      if (matrix[i][j] == '1' && !visited[i][j])
        ans += dfs(i, j);
  cout << ans << '\n';
}
