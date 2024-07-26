#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int w, h, n;
  while (cin >> w >> h >> n && w && h) {
    vector<vector<bool>> matrix(h, vector<bool>(w, false));
    for (int m = 0; m < n; ++m) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      x1--, x2--, y1--, y2--;

      if (y1 > y2)
        swap(y1, y2);
      if (x1 > x2)
        swap(x1, x2);

      for (int i = y1; i <= y2; ++i)
        for (int j = x1; j <= x2; ++j)
          matrix[i][j] = true;
    }

    int ans = 0;
    for (auto &row : matrix)
      for (const auto &cell : row)
        if (!cell)
          ans++;
    if (ans > 1)
      cout << "There are " << ans << " empty spots.\n";
    else if (ans == 1)
      cout << "There is one empty spot.\n";
    else
      cout << "There is no empty spots.\n";
  }
}
