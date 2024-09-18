#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;


int lot[252][252];
char used[252][252];
vector<int> cur, best;
int r, c;
int n, m;
bool found = false;

void backtrack(int i, int j) {
  if (i == r && j == c) {
    if (best.size() > cur.size() || !found)
      best = cur, found = true;
    return;
  }
  

  // UP
  if (i > 1 && !used[i-2][j] && lot[i-1][j] != -2 && lot[i-1][j] == lot[i-2][j]) {
    lot[i-2][j] = -1;
    lot[i][j] = lot[i-1][j];
    used[i][j] = true;
    cur.push_back(lot[i-1][j]);
    if (cur.size() < best.size() || !found)
      backtrack(i-2, j);
    cur.pop_back();
    lot[i-2][j] = lot[i-1][j];
    lot[i][j] = -1;
    used[i][j] = false;
  }
  
  // DOWN
  if (i < n - 2 && !used[i+2][j] && lot[i+1][j] != -2 && lot[i+1][j] == lot[i+2][j]) {
    lot[i+2][j] = -1;
    lot[i][j] = lot[i+1][j];
    used[i][j] = true;
    cur.push_back(lot[i+1][j]);
    if (cur.size() < best.size() || !found)
      backtrack(i+2, j);
    cur.pop_back();
    lot[i+2][j] = lot[i+1][j];
    lot[i][j] = -1;
    used[i][j] = false;
  }
  
  // LEFT
  if (j > 1 && !used[i][j-2] && lot[i][j-1] != -2 && lot[i][j-1] == lot[i][j-2]) {
    lot[i][j-2] = -1;
    lot[i][j] = lot[i][j-1];
    used[i][j] = true;
    cur.push_back(lot[i][j-1]);
    if (cur.size() < best.size() || !found)
      backtrack(i, j-2);
    cur.pop_back();
    lot[i][j-2] = lot[i][j-1];
    lot[i][j] = -1;
    used[i][j] = false;
  }

  // RIGHT
  if (j < m - 2 && !used[i][j+2] && lot[i][j+1] != -2 && lot[i][j+1] == lot[i][j+2]) {
    lot[i][j+2] = -1;
    lot[i][j] = lot[i][j+1];
    used[i][j] = true;
    cur.push_back(lot[i][j+1]);
    if (cur.size() < best.size() || !found)
      backtrack(i, j+2);
    cur.pop_back();
    lot[i][j+2] = lot[i][j+1];
    lot[i][j] = -1;
    used[i][j] = false;
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  
  memset(lot, -2, sizeof(lot));
  int ii, jj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> lot[i][j];
      if (lot[i][j] == -1)
        ii = i, jj = j;
    }
  }
  
  cin >> r >> c;
  r--, c--;
  cout << best.size() << '\n';
  
  memset(used, 0, sizeof(used));
  backtrack(ii, jj);
  
  if (!best.size())
    cout << "impossible";
  else
    for (auto& c : best)
      cout << c << ' ';
  cout << endl;
}
