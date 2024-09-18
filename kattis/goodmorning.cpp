#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<int> possible;
vector<vector<char>> board = {
    {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'\0', '0', '\0'}};

inline bool inside(int i, int j) { return i >= 0 && i <= 3 && j >= 0 && j < 3; }

void backtrack(int i, int j, string &cur) {
  if (cur.size() && stoi(cur) > 300)
    return;

  if (board[i][j] != '\0') {
    for (int k = 0; k < 3; ++k) {
      cur.push_back(board[i][j]);

      if (cur.size() < 4)
        possible.push_back(stoi(cur));

      if (inside(i + 1, j))
        backtrack(i + 1, j, cur);
      if (inside(i, j + 1))
        backtrack(i, j + 1, cur);
    }

    cur.pop_back();
    cur.pop_back();
    cur.pop_back();
  }
  if (inside(i + 1, j))
    backtrack(i + 1, j, cur);
  if (inside(i, j + 1))
    backtrack(i, j + 1, cur);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string buf;
  backtrack(0, 0, buf);
  backtrack(0, 1, buf);
  backtrack(0, 2, buf);
  sort(possible.begin(), possible.end());

  vector<int> final;
  final.push_back(possible[0]);
  for (int i = 1; i < possible.size(); ++i)
    if (possible[i] != possible[i - 1])
      final.push_back(possible[i]); //, cout << possible[i] << ' ';
  cout << endl;

  int t;
  cin >> t;

  while (t--) {
    int k;
    cin >> k;

    auto it = lower_bound(final.begin(), final.end(), k);
    int after = 1e9, before = 1e9;

    if (it != final.end())
      after = *it;
    if (it != final.begin())
      before = *(it - 1);

    if (abs(k - before) < abs(k - after))
      cout << before << '\n';
    else
      cout << after << '\n';
  }
}
