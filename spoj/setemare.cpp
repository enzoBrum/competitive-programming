#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                          {0, 1},   {1, -1}, {1, 0},  {1, 1}};

inline bool valid(vector<vector<char>> &board, const pii &pos,
                  bool check_cells = true) {
  return pos.first >= 0 && pos.first < board.size() && pos.second >= 0 &&
         pos.second < board[0].size() &&
         (!check_cells || (board[pos.first][pos.second] != 'E' &&
                           board[pos.first][pos.second] != '#'));
}

bool backtrack(vector<vector<char>> &board, vector<pii> &ships, pii &my_ship,
               int depth = 0) {
  if (board[my_ship.first][my_ship.second] != 'S')
    return false;
  if (depth > 9)
    return false;
  if (all_of(ships.begin(), ships.end(), [&board](const pii &s) {
        return board[s.first][s.second] != 'E';
      }))
    return true;

  stack<tuple<int, pii, char, pii, char>> changes;
  vector<bool> active_ships(ships.size(), false);
  for (int i = 0; i < ships.size(); ++i) {
    auto &[ey, ex] = ships[i];
    if (board[ey][ex] != 'E')
      continue;
    active_ships[i] = true;
    board[ey][ex] = '.';
    changes.push({i, {ey, ex}, 'E', {ey, ex}, 'E'});
  }

  int sz = changes.size();
  for (auto [dy, dx] : directions) {
    if (!valid(board, {my_ship.first + dy, my_ship.second + dx}))
      continue;

    changes.push(
        {-1, my_ship, 'S', {my_ship.first + dy, my_ship.second + dx}, '.'});

    board[my_ship.first][my_ship.second] = '.';
    my_ship.first += dy;
    my_ship.second += dx;
    board[my_ship.first][my_ship.second] = 'S';

    for (int i = 0; i < ships.size(); ++i) {
      auto [ey, ex] = ships[i];
      if (board[my_ship.first][my_ship.second] != 'S')
        break;
      if (!active_ships[i])
        continue;
      pii new_pos;

      if (ey < my_ship.first)
        new_pos.first = ey + 1;
      else if (ey > my_ship.first)
        new_pos.first = ey - 1;
      else
        new_pos.first = ey;

      if (ex < my_ship.second)
        new_pos.second = ex + 1;
      else if (ex > my_ship.second)
        new_pos.second = ex - 1;
      else
        new_pos.second = ex;

      char old_cell = board[ey][ex];
      char new_cell = board[new_pos.first][new_pos.second];

      ships[i] = new_pos;
      board[new_pos.first][new_pos.second] =
          board[new_pos.first][new_pos.second] != '.' ? '#' : 'E';

      changes.push({i, {ey, ex}, old_cell, new_pos, new_cell});
    }

    if (backtrack(board, ships, my_ship, depth + 1))
      return true;

    while (changes.size() > sz) {
      auto [idx, old_pos, old_cell, new_pos, new_cell] = changes.top();
      changes.pop();

      board[old_pos.first][old_pos.second] = old_cell;
      board[new_pos.first][new_pos.second] = new_cell;

      if (idx == -1)
        my_ship = old_pos;
      else
        ships[idx] = old_pos;
    }
  }
  while (!changes.empty()) {
    auto [idx, old_pos, old_cell, new_pos, new_cell] = changes.top();
    changes.pop();

    board[old_pos.first][old_pos.second] = old_cell;
    board[new_pos.first][new_pos.second] = new_cell;

    if (idx == -1)
      my_ship = old_pos;
    else
      ships[idx] = old_pos;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    vector<vector<char>> board(9, vector<char>(8));
    vector<pii> ships;
    pii my_ship;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 8; ++j) {
        cin >> board[i][j];
        if (board[i][j] == 'S')
          my_ship = {i, j};
        else if (board[i][j] == 'E')
          ships.push_back({i, j});
      }
    }

    cout << (backtrack(board, ships, my_ship)
                 ? "I'm the king of the Seven Seas!"
                 : "Oh no! I'm a dead man!")
         << '\n';
  }
}
