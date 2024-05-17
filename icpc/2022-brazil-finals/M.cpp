#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>

using namespace std;
using pii = pair<int, int>;

/*


Estado:
  - estado atual da nut -> índice num vetor de estados possíveis
  - linha atual         -> índice da linha.
  - id                  --> hash dos dois
 * */

struct State {
  int line;
  int nut;

  bool operator==(const State &other) const {
    return line == other.line && nut == other.nut;
  }
  bool operator<(const State &other) const {
    return line != other.line ? line < other.line : nut < other.nut;
  }
};

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

char maze[1024][128];
char nut_states[128][128];
bool visited[1024][128];
int r, c;

bool inv_states[1024][128];
inline bool is_valid(pii &p) {
  if (inv_states[p.second][p.first])
    return false;

  for (int i = 0; i < c; ++i)
    if (nut_states[p.first][i] == '1' && maze[p.second][i] == '1') {
      inv_states[p.second][p.first] = true;
      return false;
    }
  return true;
}

bool backtrack(pii p) {
  if (visited[p.second][p.first])
    return false;
  if (p.second == r - 1 && is_valid(p))
    return true;
  if (p.second < 0)
    return false;

  visited[p.second][p.first] = true;
  if (is_valid(p)) {
    p.second++;
    if (is_valid(p) && backtrack(p))
      return true;
    p.second -= 2;
    if (is_valid(p) && backtrack(p))
      return true;
    p.second++;
  }
  p.first = (p.first + 1) % c;

  return backtrack(p);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> r >> c;

  vector<char> init(c);
  for (auto &v : init)
    cin >> v;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      visited[i][j] = false;
      inv_states[i][j] = false;
    }
  }

  for (int j = 0; j < c; ++j)
    nut_states[0][j] = init[j];

  vector<char> tmp = init;
  vector<char> og_init = init;
  for (int i = 1; i < c; ++i) {
    for (int j = 0; j < c; ++j)
      tmp[j] = init[(j + 1) % c];
    for (int j = 0; j < c; ++j)
      nut_states[i][j] = tmp[j];
    init = tmp;
  }

  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cin >> maze[i][j];

  pii p;
  p.second = p.first = 0;

  for (int i = 0; i < c; ++i) {
    if (backtrack(p)) {
      cout << "Y\n";
      return 0;
    }
    p.first++;
  }
  reverse(og_init.begin(), og_init.end());
  init = og_init;
  tmp = og_init;
  for (int j = 0; j < c; ++j)
    nut_states[0][j] = tmp[j];
  for (int i = 1; i < c; ++i) {
    for (int j = 0; j < c; ++j)
      tmp[j] = init[(j + 1) % c];
    for (int j = 0; j < c; ++j)
      nut_states[i][j] = tmp[j];
    init = tmp;
  }

  // for (auto &s1 : nut_states) {
  //   for (auto &v : s1)
  //     cout << v;
  //   cout << endl;
  // }

  p.first = 0;
  p.second = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      visited[i][j] = false;
      inv_states[i][j] = false;
    }
  }

  for (int i = 0; i < c; ++i) {
    if (backtrack(p)) {
      cout << "Y\n";
      return 0;
    }
    p.first++;
  }

#ifdef DEBUG
#define PRINT(s) cout << s << '\n';
#else
#define PRINT(s)                                                               \
  {}
#endif

  PRINT("ABCD")

  cout << "N\n";
}
