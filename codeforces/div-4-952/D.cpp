#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto &r : grid)
      cin >> r;

    int row = -1, best = -1;
    for (int i = 0; i < n; ++i) {
      int num = count(grid[i].begin(), grid[i].end(), '#');

      if (num > best) {
        row = i;
        best = num;
      }
    }

    int column = grid[row].find_first_of('#') + best / 2;
    cout << row + 1 << ' ' << column + 1 << '\n';
  }
}
