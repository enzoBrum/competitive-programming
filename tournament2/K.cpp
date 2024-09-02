#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

using iiii = tuple<int, int, int, int>;

vector<pii> moves = {{-1, -2}, {1, -2}, {1, 2}, {-1, 2},
                     {-2, -1}, {-2, 1}, {2, 1}, {2, -1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<vector<int>> board(n, vector<int>(n, -1));

  vector<tuple<int, int, int, int>> knights(k);
  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    board[a][b] = i;
    knights[i] = {a, b, 0, 0};
  }

  for (int i = 0; i < k; ++i) {
    auto&[ia, ij, attack, attacked] = knights[i];
    for (auto&[mi, mj] : moves) {
      if (ia + mi >= 0 && ia + mi < n && ij + mj >= 0 && ij + mj < n && board[ia+mi][ij+mj] != -1) {
        auto&[ib, bij, battack, battacked] = knights[board[ia+mi][ij+mj]];
        battacked++;
        attack++;
      }
    }
  }

  sort(knights.begin(), knights.end(), [](iiii& a, iiii& b) {
    return get<2>(a) > get<2>(b);
  });



  for (int i = 0; i < k; ++i) {
    board[get<0>(knights[i])][get<1>(knights[i])] = i;
  }

  int ans = 0;
  for (int kk = 0; kk < k; ++kk) {
    auto&[ia, ja, attack, attacked] = knights[kk];
    if (!attack)
      continue;

    ans++;
    for (auto&[mi, mj] : moves) {
      if (ia + mi >= 0 && ia + mi < n && ja + mj >= 0 && ja + mj < n && board[ia+mi][ja+mj] != -1) {
        auto&[ib, bij, battack, battacked] = knights[board[ia+mi][ja+mj]];
        battack--, battacked--;
      }
    }

    if (kk != k - 1)
      sort(knights.begin() + kk + 1, knights.end(), [](iiii& a, iiii& b) {
        return get<2>(a) > get<2>(b);
      });
  }

  cout << ans << '\n';
}
