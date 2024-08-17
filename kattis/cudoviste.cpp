#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int r, c;
  cin >> r >> c;

  vector<vector<int>> city(r, vector<int>(c));
  for (auto& row : city) {
    for (auto& col : row) {
      char c;
      cin >> c;

      if (c == '.')
        col = 0;
      else if (c == 'X')
        col = 1;
      else
        col = -1000;
    }
  }
  
  vector<int> ans(5);
  for (int i = 0; i < r - 1; ++i) {
    for (int j = 0; j < c - 1; j++) {
      int squashed = city[i][j] + city[i][j+1] + city[i+1][j] + city[i+1][j+1];
      if (squashed < 0)
        continue;
      ans[squashed]++;
    }
  }
  
  for (auto& v : ans)
    cout << v << '\n';
}
