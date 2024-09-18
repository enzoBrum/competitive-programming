#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool used[10];
int n;
vector<string> dances;

int backtrack(int depth, int prev) {
  if (depth == n)
    return 0;

  int best = 0;
  for (int i = 0; i < n; ++i) {
    if (used[i])
      continue;
    used[i] = true;

    int count[26];
    memset(count, 0, sizeof(count));
    int cur = 0;
    if (depth > 0) {
      for (auto &c : dances[prev])
        count[c - 'A']++;
      for (auto &c : dances[i])
        count[c - 'A']++;
      for (int i = 0; i < 26; ++i)
        if (count[i] == 2)
          cur++;
    }
    cur += backtrack(depth + 1, i);
    best = min(best, cur);
    used[i] = false;
  }
  return best;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  memset(used, 0, sizeof(used));

  dances.resize(n);
  for (auto &v : dances)
    cin >> v;

  cout << backtrack(0, -1) << '\n';
}
